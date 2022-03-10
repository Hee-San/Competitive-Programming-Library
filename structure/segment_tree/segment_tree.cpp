/**
 * @brief Segment Tree(セグメント木, 一点を更新・区間の演算結果を取得)
 * @docs docs/structure/segment_tree/segment_tree.md
 */

using namespace std;

template <typename T>
struct SegmentTree {
    typedef T (*F)(T, T);
    int n;
    vector<T> seg;
    F function;
    T identity;

    SegmentTree(int n, F function, T identity) : n(n), function(function), identity(identity) {
        seg.assign(2 * n, identity);
    }

    void build(vector<T> v) {
        assert(n == (int)v.size());
        for (int i = 0; i < n; i++) seg[n + i] = v[i];
        for (int i = n - 1; i > 0; i--) seg[i] = function(seg[2 * i], seg[2 * i + 1]);
    }

    void update(int x, T val) {
        x += n;
        seg[x] = val;
        while (x > 1) {
            x = x / 2;
            seg[x] = function(seg[2 * x], seg[2 * x + 1]);
        }
    }

    T get(int x) {
        x += n;
        return seg[x];
    }

    T get(int l, int r) {
        T left = identity;
        T right = identity;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) left = function(left, seg[l++]);
            if (r % 2) right = function(seg[--r], right);
        }
        return function(left, right);
    }
};