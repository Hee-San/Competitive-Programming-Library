/**
 * @brief Lazy Segment Tree(遅延セグメント木)
 * @docs docs/structure/segment_tree/lazy_segment_tree.md
 */

#include "../../common/common.cpp"
using namespace std;

// 遅延セグメント木
// S: モノイドの型。各要素や区間の演算結果の型
// F: 写像(S -> S)の属性を持つ型。その属性として、区間に対して操作をするときの引数を持つ
// モノイド(S : op(S, S) -> S, e : S)と、SからSへの写像の集合(F : mapping(F, S) -> S)が次の条件を満たすとき、遅延セグメント木を構築できる
// 1. Fは恒等写像idを持つ。すなわち、任意のSに対してmapping(id, S) = Sが成り立つ
// 2. Fは写像の合成について閉じている。すなわち、任意のf, g ∈ Fに対してcomposition(f, g) ∈ Fが成り立つ
// 3. f ∈ F, x,y ∈ Sに対して、mapping(f, op(x, y)) = op(mapping(f, x), mapping(f, y))が成り立つ

/// @brief 遅延セグメント木
/// @tparam S モノイドの型
/// @tparam F 写像(S -> S)の属性を持つ型
/// @tparam op 'S x S -> S'を計算する関数
/// @tparam e opの単位元
/// @tparam mapping 'F x S -> S'を計算する関数。fの属性を使って、fを適用した結果を計算する。
/// @tparam composition 写像の合成'F x F -> F'を計算する関数
/// @tparam id 恒等写像(compositionの単位元)
template <class S, S(*op)(S, S), S(*e)(), class F, S(*mapping)(F, S), F(*composition)(F, F), F(*id)()>
struct LazySegmentTree {
public:
    LazySegmentTree() : LazySegmentTree(0) {}
    explicit LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}
    explicit LazySegmentTree(const vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n)); // bit_ceil: 2の累乗値に切り上げ
        log = internal::countr_zero((unsigned int)size); // countr_zero: 末尾の0の数を数える
        d = vector<S>(2 * size, e());
        lz = vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    /// @brief 葉の要素数
    int _n;
    /// @brief セグメント木の幅(要素数が2の累乗になるまで拡張したときの、拡張後の葉の要素数)
    int size;
    /// @brief 二分木の深さ
    int log;
    /// @brief ノードの値
    vector<S> d;
    /// @brief 遅延評価用の値
    vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
    void visualize(function<string(S)> s2str, function<string(F)> f2str) {
        /// @brief ノードの表示幅
        vi width(2 * size);
        /// @brief ノードのインデックスを表す文字列
        vs index(2 * size);
        rep(i, 2 * size) {
            index[i] = "[" + to_string(i) + "]";
        }
        /// @brief ノードの範囲を表す文字列
        vs range(2 * size);
        rep(i, size) {
            if (i >= _n) {
                range[i + size] = "[" + to_string(i - _n) + "]";
            } else {
                int l = 
            }
        }
        /// @brief ノードの値を表す文字列
        vs value(2 * size);
        /// @brief ノードの遅延評価用の値を表す文字列
        vs lazy(2 * size);
    }
};
