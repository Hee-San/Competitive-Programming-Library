#include "../../common/common.cpp"
using namespace std;

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木, 一点代入, 区間取得)
 * @brief 一点代入時に、即座に関係する積を更新する
 * @docs docs/structure/segment_tree/segment_tree.md
 * @tparam Monoid 値と、それに対する操作を定義するモノイド
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    int n; // 配列の要素数
    int leaf_size; // 葉の数
    /**
     * @brief 完全二分木の配列
     * tree[0] は使わない
     * 2 * leaf_size がノード数
     * [leaf_size, 2 * leaf_size) が葉
    */
    vector<value_type> tree;

    /**
     * @brief n 要素の配列を持つセグメント木を構築する
     * @param n_ 配列の要素数
     * @param mon_ モノイド
     * @note $O(n)$
     */
    explicit segment_tree(const int n_, const Monoid& mon_ = Monoid()) : mon(mon_), n(n_) {
        leaf_size = 1;
        while (leaf_size < n) leaf_size <<= 1; // n 以上の最小の 2 冪
        tree.assign(2 * leaf_size, mon.unit());
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
        tree.assign(2 * leaf_size, mon.unit());
        for (int i = 0; i < n; ++i) tree[i + leaf_size] = vec[i];
        build();
    }

    /**
     * @brief 積を計算をせずに、i 番目の要素を x に代入する
     * @param i 代入する要素のインデックス
     * @param x 代入後の値
     * @note $O(1)$
    */
    void unsafe_set(int i, const value_type& x) {
        assert(0 <= i && i < n); // i は [0, n) の範囲
        tree[i + leaf_size] = x;
    }

    /**
     * @brief 葉以外のノードで積を計算する
     * @note $O(n)$
    */
    void build() {
        for (int i = leaf_size - 1; i > 0; --i) {
            tree[i] = mon.mult(tree[2 * i], tree[2 * i + 1]);
        }
    }

    /**
     * @brief i 番目の要素に x を代入し、積を再計算する
     * @param x 代入後の値
     * @note $O(\log n)$
     */
    void point_set(int i, const value_type& x) {
        assert(0 <= i && i < n); // i は [0, n) の範囲
        int index = i + leaf_size; // tree 上での位置
        // 葉に代入
        tree[index] = x;
        // 葉から根に向かって積を計算
        while (index > 1) {
            index /= 2;
            tree[index] = mon.mult(tree[2 * index], tree[2 * index + 1]);
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
        int index_l = l + leaf_size; // tree 上での左端
        int index_r = r + leaf_size; // tree 上での右端
        while (index_l < index_r) {
            if (index_l & 1) res_l = mon.mult(res_l, tree[index_l++]); // 左端が右の子の場合、積を更新してから右に移動
            if (index_r & 1) res_r = mon.mult(tree[--index_r], res_r); // 右端が右の子の場合、積を更新してから左に移動
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
        return tree[i + leaf_size];
    }

    /**
     * @brief セグメント木を可視化する
     * @note デバッグ用
     * @note $O(n)$
     * @note 以下のように出力される
     * @note _0:_|____________________343|
     * @note _1:_|________189|________154|
     * @note _2:_|__140|___49|___91|___63|
     * @note _3:_|60|80|24|25|19|72|25|38|
    */
    void visualize_for_debug() {
        int h = 0; // 木の高さ
        while ((1 << h) < 2 * leaf_size) ++h;

        int max_val_width = 0;
        for (value_type v : tree) {
            max_val_width = max(max_val_width, (int)to_string(v).size() + 1);
        }

        for (int i = 0; i < h; ++i) {
            cout << setw(2) << i << ": |";
            int cell_width = (1 << (h - i - 1));
            for (int j = 0; j < (1 << i); ++j) {
                cout << setw(max_val_width * cell_width - 1) << tree[(1 << i) + j] << "|";
            }
            cout << endl;
        }
        cout << endl;
    }
};
