---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/DSL_2_A.test.cpp
    title: "\u533A\u9593\u306E\u6700\u5C0F\u5024\u30FB\u4E00\u70B9\u66F4\u65B0 Range\
      \ Minimum Query (RMQ)"
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/DSL_2_B.test.cpp
    title: "\u533A\u9593\u306E\u548C\u30FB\u4E00\u70B9\u52A0\u7B97 Range Sum Query\
      \ (RSQ)"
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
    title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/structure/segment_tree/segment_tree.md
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\
      \u3092\u66F4\u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\
      \u5F97)"
    links: []
  bundledCode: "#line 1 \"structure/segment_tree/segment_tree.cpp\"\n/**\n * @brief\
    \ Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\u65B0\
    \u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)\n * @docs\
    \ docs/structure/segment_tree/segment_tree.md\n */\n\nusing namespace std;\n\n\
    template <typename T>\nstruct SegmentTree {\n    typedef T (*F)(T, T);\n    int\
    \ n, height, width;\n    vector<T> seg;\n    F function;\n    T identity;\n\n\
    \    SegmentTree(int n, F function, T identity) : n(n), function(function), identity(identity)\
    \ {\n        height = 1, width = 1;\n        while (width < n) {\n           \
    \ height++;\n            width *= 2;\n        }\n        seg.assign(2 * width\
    \ - 1, identity);\n    }\n\n    void build(vector<T> v) {\n        assert(n ==\
    \ (int)v.size());\n        for (int i = 0; i < n; i++) seg[width + i - 1] = v[i];\n\
    \        for (int i = width - 2; i >= 0; i--) seg[i] = function(seg[2 * i + 1],\
    \ seg[2 * i + 2]);\n    }\n\n    void update(int x, T val) {\n        x += width\
    \ - 1;\n        seg[x] = val;\n        while (x > 0) {\n            x = (x - 1)\
    \ / 2;\n            seg[x] = function(seg[2 * x + 1], seg[2 * x + 2]);\n     \
    \   }\n    }\n\n    T get(int x) {\n        x += width - 1;\n        return seg[x];\n\
    \    }\n\n    T get(int a, int b, int k = 0, int l = 0, int r = -1) {\n      \
    \  if (r < 0) r = width;\n        if (r <= a || b <= l) return identity;\n   \
    \     if (a <= l && r <= b) return seg[k];\n        T vl = get(a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);\n   \
    \     return function(vl, vr);\n    }\n};\n"
  code: "/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\
    \u3092\u66F4\u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\
    \u5F97)\n * @docs docs/structure/segment_tree/segment_tree.md\n */\n\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct SegmentTree {\n    typedef T (*F)(T, T);\n\
    \    int n, height, width;\n    vector<T> seg;\n    F function;\n    T identity;\n\
    \n    SegmentTree(int n, F function, T identity) : n(n), function(function), identity(identity)\
    \ {\n        height = 1, width = 1;\n        while (width < n) {\n           \
    \ height++;\n            width *= 2;\n        }\n        seg.assign(2 * width\
    \ - 1, identity);\n    }\n\n    void build(vector<T> v) {\n        assert(n ==\
    \ (int)v.size());\n        for (int i = 0; i < n; i++) seg[width + i - 1] = v[i];\n\
    \        for (int i = width - 2; i >= 0; i--) seg[i] = function(seg[2 * i + 1],\
    \ seg[2 * i + 2]);\n    }\n\n    void update(int x, T val) {\n        x += width\
    \ - 1;\n        seg[x] = val;\n        while (x > 0) {\n            x = (x - 1)\
    \ / 2;\n            seg[x] = function(seg[2 * x + 1], seg[2 * x + 2]);\n     \
    \   }\n    }\n\n    T get(int x) {\n        x += width - 1;\n        return seg[x];\n\
    \    }\n\n    T get(int a, int b, int k = 0, int l = 0, int r = -1) {\n      \
    \  if (r < 0) r = width;\n        if (r <= a || b <= l) return identity;\n   \
    \     if (a <= l && r <= b) return seg[k];\n        T vl = get(a, b, 2 * k + 1,\
    \ l, (l + r) / 2);\n        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);\n   \
    \     return function(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment_tree/segment_tree.cpp
  requiredBy: []
  timestamp: '2022-03-07 23:27:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  - Tests/AizuOnlineJudge/DSL_2_B.test.cpp
  - Tests/AizuOnlineJudge/DSL_2_A.test.cpp
documentation_of: structure/segment_tree/segment_tree.cpp
layout: document
redirect_from:
- /library/structure/segment_tree/segment_tree.cpp
- /library/structure/segment_tree/segment_tree.cpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\
  \u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)"
---
## 概要
  
各ノードが区間に対応した、完全二分木。
- 子は親の半分の区間を持つ  
- モノイドについて、区間に対する演算が$O(log(n))$で処理できる。
  - 単位元の存在・結合律

セグメント木とは → https://www.slideshare.net/iwiwi/ss-3578491
実装について → https://tsutaj.hatenablog.com/entry/2017/03/29/204841

## 使い方

**区間に対して更新を高速に行いたい場合は、遅延セグメント木を使う。**

`SegmentTree(n, f, id)` : サイズが`n`のセグメント木を作成する。
  - `f` : 区間に対する演算
  - `id` : 単位元

ex.  
  - 区間和 : `SegmentTree<ll> seg(n, [](ll a, ll b) { return a + b; }, 0);`
  - 区間max : `SegmentTree<ll> seg(n, [](ll a, ll b) { return max(a, b); }, 0);`
  - 区間min : `SegmentTree<ll> seg(n, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);`
  - 区間xor : `SegmentTree<ll> seg(n, [](ll a, ll b) { return a ^ b; }, 0);`
  - 区間GCD : `SegmentTree<ll> seg(n, [](ll a, ll b) { gcd(a, b); }, 0);`
  - 区間LCM : `SegmentTree<ll> seg(n, [](ll a, ll b) { lcm(a, b); }, 1);`

`seg.build(A)` : 配列Aをセグメント木に設定する。

`seg.update(x, val)` : x番目の値をvalに更新する。

`seg.get(x)` : x番目の値を取得する。

`seg.get(l, r)` : 区間[l, r)についての演算結果を取得する。


## 計算量

-  `build(A)` : $O(n)$
-  `update(x, val)` : $O(log(n))$
-  `get(x)` : $O(1)$
-  `get(l, r)` : $O(log(n))$