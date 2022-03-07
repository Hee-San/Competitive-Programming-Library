/**
 * @brief Segment Tree(セグメント木)
 * @docs docs/structure/segment_tree.md
 */

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n, height, width;
    vector<T> seg;
    F function;
    T identity;

    SegmentTree(int n, F function, T identity) : n(n), function(function), identity(identity) {
        height = 1, width = 1;
        while (width < n) {
            height++;
            width << 1;
        }
        seg.assign(2 * width - 1, identity);
    }
    SegmentTree(vector<T> v, F function, T identity) : SegmentTree((int)v.size(), function, identity) {
        build(v);
    }

    void build(vector<T> v) {
        assert(n == (int)v.size());
        for (int i = 0; i < n; i++) seg[width + i - 1] = v[i];
        for (int i = width - 2; i >= 0; i--) seg[i] = function(seg[2 * i], seg[2 * i + 1]);
    }

    void update(int x, T val) {
        x += width - 1;
        seg[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            seg[x] = function(seg[2 * x + 1], seg[2 * x + 2]);
        }
    }

    T get(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = width;
        if (r <= a || b <= l) return identity;
        if (a <= l && r <= b) return seg[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return function(vl, vr);
    }
};