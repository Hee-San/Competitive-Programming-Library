---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/segment_tree/segment_tree.cpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
    document_title: Range Minimum Query (RMQ)
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
  bundledCode: "#line 1 \"Tests/AizuOnlineJudge/DSL_2_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\n/**\n * @brief Range\
    \ Minimum Query (RMQ)\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"structure/segment_tree/segment_tree.cpp\"\
    \n/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs\
    \ docs/structure/segment_tree.md\n */\n\ntemplate <typename T>\nstruct SegmentTree\
    \ {\n    using F = function<T(T, T)>;\n    int n, height, width;\n    vector<T>\
    \ seg;\n    F function;\n    T identity;\n\n    SegmentTree(int n, F function,\
    \ T identity) : n(n), function(function), identity(identity) {\n        height\
    \ = 1, width = 1;\n        while (width < n) {\n            height++;\n      \
    \      width << 1;\n        }\n        seg.assign(2 * width - 1, identity);\n\
    \    }\n    SegmentTree(vector<T> v, F function, T identity) : SegmentTree((int)v.size(),\
    \ function, identity) {\n        build(v);\n    }\n\n    void build(vector<T>\
    \ v) {\n        assert(n == (int)v.size());\n        for (int i = 0; i < n; i++)\
    \ seg[width + i - 1] = v[i];\n        for (int i = width - 2; i >= 0; i--) seg[i]\
    \ = function(seg[2 * i], seg[2 * i + 1]);\n    }\n\n    void update(int x, T val)\
    \ {\n        x += width - 1;\n        seg[x] = val;\n        while (x > 0) {\n\
    \            x = (x - 1) / 2;\n            seg[x] = function(seg[2 * x + 1], seg[2\
    \ * x + 2]);\n        }\n    }\n\n    T get(int a, int b, int k = 0, int l = 0,\
    \ int r = -1) {\n        if (r < 0) r = width;\n        if (r <= a || b <= l)\
    \ return identity;\n        if (a <= l && r <= b) return seg[k];\n        T vl\
    \ = get(a, b, 2 * k + 1, l, (l + r) / 2);\n        T vr = get(a, b, 2 * k + 2,\
    \ (l + r) / 2, r);\n        return function(vl, vr);\n    }\n};\n#line 9 \"Tests/AizuOnlineJudge/DSL_2_A.test.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll n, q;\n    cin >> n >> q;\n    auto seg = SegmentTree<ll>(\n\
    \        vi(n, 1 << 31 - 1), [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n\
    \n    for (ll i = 0; i < q; i++) {\n        ll com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if (com == 0) {\n            seg.update(x, y);\n       \
    \ } else {\n            cout << seg.get(x, y + 1) << endl;\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\n/**\n\
    \ * @brief Range Minimum Query (RMQ)\n */\n\n#include <bits/stdc++.h>\n\n#include\
    \ \"../../structure/segment_tree/segment_tree.cpp\"\n\nusing namespace std;\n\
    typedef long long ll;\ntypedef vector<ll> vi;\n\nint main() {\n    ll n, q;\n\
    \    cin >> n >> q;\n    auto seg = SegmentTree<ll>(\n        vi(n, 1 << 31 -\
    \ 1), [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n\n    for (ll i = 0;\
    \ i < q; i++) {\n        ll com, x, y;\n        cin >> com >> x >> y;\n      \
    \  if (com == 0) {\n            seg.update(x, y);\n        } else {\n        \
    \    cout << seg.get(x, y + 1) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - structure/segment_tree/segment_tree.cpp
  isVerificationFile: true
  path: Tests/AizuOnlineJudge/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-03-07 14:24:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/AizuOnlineJudge/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/Tests/AizuOnlineJudge/DSL_2_A.test.cpp
- /verify/Tests/AizuOnlineJudge/DSL_2_A.test.cpp.html
title: Range Minimum Query (RMQ)
---
