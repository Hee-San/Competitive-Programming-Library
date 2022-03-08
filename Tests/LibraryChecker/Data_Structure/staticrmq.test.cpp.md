---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segment_tree/segment_tree.cpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\
      \u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ \u533A\u9593\u306E\u6700\u5C0F\u5024\n */\n\n#include <bits/stdc++.h>\n\n#line\
    \ 1 \"structure/segment_tree/segment_tree.cpp\"\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\u65B0\u30FB\u533A\u9593\
    \u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)\n * @docs docs/structure/segment_tree/segment_tree.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct SegmentTree {\n\
    \    typedef T (*F)(T, T);\n    int n;\n    vector<T> seg;\n    F function;\n\
    \    T identity;\n\n    SegmentTree(int n, F function, T identity) : n(n), function(function),\
    \ identity(identity) {\n        seg.assign(2 * n, identity);\n    }\n\n    void\
    \ build(vector<T> v) {\n        assert(n == (int)v.size());\n        for (int\
    \ i = 0; i < n; i++) seg[n + i] = v[i];\n        for (int i = n - 1; i > 0; i--)\
    \ seg[i] = function(seg[2 * i], seg[2 * i + 1]);\n    }\n\n    void update(int\
    \ x, T val) {\n        x += n;\n        seg[x] = val;\n        while (x > 1) {\n\
    \            x = x / 2;\n            seg[x] = function(seg[2 * x], seg[2 * x +\
    \ 1]);\n        }\n    }\n\n    T get(int x) {\n        x += n;\n        return\
    \ seg[x];\n    }\n\n    T get(int l, int r) {\n        T ans = identity;\n   \
    \     for (l += n, r += n; l < r; l /= 2, r /= 2) {\n            if (l % 2) ans\
    \ = function(ans, seg[l++]);\n            if (r % 2) ans = function(seg[--r],\
    \ ans);\n        }\n        return ans;\n    }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i =\
    \ 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    SegmentTree<ll> seg(\n\
    \        N, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n    seg.build(A);\n\
    \n    for (ll i = 0; i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ \u533A\u9593\u306E\u6700\u5C0F\u5024\n */\n\n#include <bits/stdc++.h>\n\n#include\
    \ \"../../../structure/segment_tree/segment_tree.cpp\"\n\nusing namespace std;\n\
    typedef long long ll;\ntypedef vector<ll> vi;\n\nint main() {\n    ll N, Q;\n\
    \    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i = 0; i < N; i++) {\n      \
    \  cin >> A[i];\n    }\n\n    SegmentTree<ll> seg(\n        N, [](ll a, ll b)\
    \ { return min(a, b); }, LLONG_MAX);\n    seg.build(A);\n\n    for (ll i = 0;\
    \ i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n        cout << seg.get(l,\
    \ r) << endl;\n    }\n}\n"
  dependsOn:
  - structure/segment_tree/segment_tree.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-03-08 21:40:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp.html
title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
---