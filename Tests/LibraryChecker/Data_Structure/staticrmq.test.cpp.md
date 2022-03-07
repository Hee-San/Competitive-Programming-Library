---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segment_tree/segment_tree.cpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: Static RMQ
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ Static RMQ\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"structure/segment_tree/segment_tree.cpp\"\
    \n/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs\
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
    \        return function(vl, vr);\n    }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i =\
    \ 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    SegmentTree<ll> seg(\n\
    \        N, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n    seg.build(A);\n\
    \n    for (ll i = 0; i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ Static RMQ\n */\n\n#include <bits/stdc++.h>\n\n#include \"../../../structure/segment_tree/segment_tree.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i =\
    \ 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    SegmentTree<ll> seg(\n\
    \        N, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n    seg.build(A);\n\
    \n    for (ll i = 0; i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}\n"
  dependsOn:
  - structure/segment_tree/segment_tree.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-03-07 17:22:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp.html
title: Static RMQ
---
