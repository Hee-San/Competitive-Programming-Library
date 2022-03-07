---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/DSL_2_A.test.cpp
    title: Range Minimum Query (RMQ)
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
    title: Static RMQ
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/structure/segment_tree/segment_tree.md
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"structure/segment_tree/segment_tree.cpp\"\n/**\n * @brief\
    \ Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/structure/segment_tree/segment_tree.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct SegmentTree {\n\
    \    typedef T (*F)(T, T);\n    int n, height, width;\n    vector<T> seg;\n  \
    \  F function;\n    T identity;\n\n    SegmentTree(int n, F function, T identity)\
    \ : n(n), function(function), identity(identity) {\n        height = 1, width\
    \ = 1;\n        while (width < n) {\n            height++;\n            width\
    \ *= 2;\n        }\n        seg.assign(2 * width - 1, identity);\n    }\n\n  \
    \  void build(vector<T> v) {\n        assert(n == (int)v.size());\n        for\
    \ (int i = 0; i < n; i++) seg[width + i - 1] = v[i];\n        for (int i = width\
    \ - 2; i >= 0; i--) seg[i] = function(seg[2 * i + 1], seg[2 * i + 2]);\n    }\n\
    \n    void update(int x, T val) {\n        x += width - 1;\n        seg[x] = val;\n\
    \        while (x > 0) {\n            x = (x - 1) / 2;\n            seg[x] = function(seg[2\
    \ * x + 1], seg[2 * x + 2]);\n        }\n    }\n\n    T get(int a, int b, int\
    \ k = 0, int l = 0, int r = -1) {\n        if (r < 0) r = width;\n        if (r\
    \ <= a || b <= l) return identity;\n        if (a <= l && r <= b) return seg[k];\n\
    \        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);\n        T vr = get(a, b,\
    \ 2 * k + 2, (l + r) / 2, r);\n        return function(vl, vr);\n    }\n};\n"
  code: "/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs\
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
    \   }\n    }\n\n    T get(int a, int b, int k = 0, int l = 0, int r = -1) {\n\
    \        if (r < 0) r = width;\n        if (r <= a || b <= l) return identity;\n\
    \        if (a <= l && r <= b) return seg[k];\n        T vl = get(a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \        return function(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment_tree/segment_tree.cpp
  requiredBy: []
  timestamp: '2022-03-07 17:22:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  - Tests/AizuOnlineJudge/DSL_2_A.test.cpp
documentation_of: structure/segment_tree/segment_tree.cpp
layout: document
redirect_from:
- /library/structure/segment_tree/segment_tree.cpp
- /library/structure/segment_tree/segment_tree.cpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
