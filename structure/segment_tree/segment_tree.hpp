#include "../../common/common.cpp"
using namespace std;

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木, 一点更新, 区間取得)
 * @docs docs/structure/segment_tree/segment_tree.md
 * @tparam Monoid (可換でなくてOK)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    int n; // 配列の要素数
    int leaf_size; // 葉の数
    /**
     * @brief 完全二分木の配列
     * dat[0] は使わない
     * 2 * leaf_size がノード数
     * [leaf_size, 2 * leaf_size) が葉
    */
    vector<value_type> dat;

    /**
     * @brief n 要素の配列を持つセグメント木を構築する
     * @param n_ 配列の要素数
     * @param mon_ モノイド
     * @note $O(n)$
     */
    explicit segment_tree(const int n_, const Monoid& mon_ = Monoid()) : mon(mon_), n(n_) {
        leaf_size = 1;
        while (leaf_size < n) leaf_size <<= 1; // n 以上の最小の 2 冪
        dat.assign(2 * leaf_size, mon.unit());
    }

    /**
     * @brief 配列からセグメント木を構築する
     * @param v 配列
     * @param mon_ モノイド
     * @note $O(n)$
     */
    explicit segment_tree(const vector<value_type>& vec, const Monoid& mon_ = Monoid()) : mon(mon_), n(vec.size()) {
        leaf_size = 1;
        while (leaf_size < n) leaf_size <<= 1; // n 以上の最小の 2 冪
        dat.assign(2 * leaf_size, mon.unit());
        for (int i = 0; i < n; ++i) dat[i + leaf_size] = vec[i];
        build();
    }

    /**
     * @brief 木の更新をせずに、i 番目の要素を x に更新する
     * @param i 更新する要素のインデックス
     * @param x 更新後の値
     * @note $O(1)$
    */
    void unsafe_set(int i, const value_type& x) {
        assert(0 <= i && i < n); // i は [0, n) の範囲
        dat[i + leaf_size] = x;
    }

    /**
     * @brief 葉以外のノードを更新する
     * @note $O(n)$
    */
    void build() {
        for (int i = leaf_size - 1; i > 0; --i) {
            dat[i] = mon.mult(dat[2 * i], dat[2 * i + 1]);
        }
    }

    /**
     * @brief i 番目の要素を x に更新し、根に向かって更新する
     * @param x 更新後の値
     * @note $O(\log n)$
     */
    void point_set(int i, const value_type& x) {
        assert(0 <= i && i < n); // i は [0, n) の範囲
        int index = i + leaf_size; // dat 上での位置
        // 葉から根に向かって更新
        dat[index] = x;
        while (index > 1) {
            index /= 2;
            dat[index] = mon.mult(dat[2 * index], dat[2 * index + 1]);
        }
    }

    /**
     * @brief [l, r) の範囲の積を求める
     * @param l 範囲の左端
     * @param r 範囲の右端
     * @return value_type [l, r) の範囲の積
     * @note $O(\log n)$
     */
    value_type range_get(int l, int r) {
        assert(0 <= l && l <= r && r <= n); // [l, r) は [0, n) の部分区間
        value_type res_l = mon.unit(), res_r = mon.unit();
        int index_l = l + leaf_size; // dat 上での左端
        int index_r = r + leaf_size; // dat 上での右端
        while (index_l < index_r) {
            if (index_l & 1) res_l = mon.mult(res_l, dat[index_l++]); // 左端が右の子の場合、積を更新してから右に移動
            if (index_r & 1) res_r = mon.mult(dat[--index_r], res_r); // 右端が右の子の場合、積を更新してから左に移動
            index_l /= 2;
            index_r /= 2;
        }
        return mon.mult(res_l, res_r);
    }

    /**
     * @brief i 番目の要素を取得する
     * @param i 取得する要素のインデックス
     * @return value_type i 番目の要素
     * @note $O(1)$
     */
    value_type point_get(int i) {
        assert(0 <= i && i < n); // i は [0, n) の範囲
        return dat[i + leaf_size];
    }
};
