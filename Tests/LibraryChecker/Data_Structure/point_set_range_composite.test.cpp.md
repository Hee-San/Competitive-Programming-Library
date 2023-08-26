---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: common/common.cpp
    title: "\u5171\u901A\u8A2D\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    document_title: "\u975E\u53EF\u63DB\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n/**\n * @brief \u975E\u53EF\u63DB\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\
    \n#include <bits/stdc++.h>\n\n#line 1 \"structure/segment_tree/segment_tree.cpp\"\
    \n/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\
    \u3092\u66F4\u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\
    \u5F97)\n * @docs docs/structure/segment_tree/segment_tree.md\n */\n\n#line 1\
    \ \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\n * @docs docs/common/common.md\n\
    \ */\n\n#line 7 \"common/common.cpp\"\nusing namespace std;\n\ntypedef long long\
    \ ll;\ntypedef vector<int> vi;\ntypedef vector<vi> vvi;\ntypedef vector<ll> vl;\n\
    typedef vector<vl> vvl;\ntypedef vector<bool> vb;\ntypedef vector<string> vs;\n\
    \n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define rep2(i, n) for\
    \ (int i = (n)-1; i >= 0; i--)\n#define rep3(i, m, n) for (int i = (m); i < (int)(n);\
    \ i++)\n#line 7 \"structure/segment_tree/segment_tree.cpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct SegmentTree {\n  typedef T(*F)(T, T);\n  int n;\n\
    \  vector<T> seg;\n  F function;\n  T identity;\n\n  SegmentTree(int n, F function,\
    \ T identity)\n    : n(n), function(function), identity(identity) {\n    seg.assign(2\
    \ * n, identity);\n  }\n\n  void build(vector<T> v) {\n    assert(n == (int)v.size());\n\
    \    rep(i, n) seg[n + i] = v[i];\n    rep2(i, n) seg[i] = function(seg[2 * i],\
    \ seg[2 * i + 1]);\n  }\n\n  void update(int x, T val) {\n    x += n;\n    seg[x]\
    \ = val;\n    while (x > 1) {\n      x = x / 2;\n      seg[x] = function(seg[2\
    \ * x], seg[2 * x + 1]);\n    }\n  }\n\n  T get(int x) {\n    x += n;\n    return\
    \ seg[x];\n  }\n\n  T get(int l, int r) {\n    T left = identity;\n    T right\
    \ = identity;\n    for (l += n, r += n; l < r; l /= 2, r /= 2) {\n      if (l\
    \ % 2) left = function(left, seg[l++]);\n      if (r % 2) right = function(seg[--r],\
    \ right);\n    }\n    return function(left, right);\n  }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp\"\
    \n\nusing namespace std;\ntypedef pair<ll, ll> pl;\ntypedef vector<pl> vpl;\n\n\
    ll MOD = 998244353;\n\nint main() {\n  ll N, Q;\n  cin >> N >> Q;\n\n  SegmentTree<pl>\
    \ seg(\n    N,\n    [](pl a, pl b) {\n      return pl{ (a.first * b.first) % MOD,\n\
    \                 (a.second * b.first + b.second) % MOD };\n    },\n    pl(1,\
    \ 0));\n\n  vpl ab(N);\n  for (int i = 0; i < N; i++) {\n    ll a, b;\n    cin\
    \ >> a >> b;\n    ab[i] = pl(a, b);\n  }\n  seg.build(ab);\n\n  for (int i = 0;\
    \ i < Q; i++) {\n    int q;\n    cin >> q;\n    if (q == 0) {\n      ll p, c,\
    \ d;\n      cin >> p >> c >> d;\n      seg.update(p, pl(c, d));\n    } else {\n\
    \      ll l, r, x;\n      cin >> l >> r >> x;\n      pl p = seg.get(l, r);\n \
    \     cout << (p.first * x + p.second) % MOD << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n/**\n * @brief \u975E\u53EF\u63DB\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\
    \n#include <bits/stdc++.h>\n\n#include \"../../../structure/segment_tree/segment_tree.cpp\"\
    \n\nusing namespace std;\ntypedef pair<ll, ll> pl;\ntypedef vector<pl> vpl;\n\n\
    ll MOD = 998244353;\n\nint main() {\n  ll N, Q;\n  cin >> N >> Q;\n\n  SegmentTree<pl>\
    \ seg(\n    N,\n    [](pl a, pl b) {\n      return pl{ (a.first * b.first) % MOD,\n\
    \                 (a.second * b.first + b.second) % MOD };\n    },\n    pl(1,\
    \ 0));\n\n  vpl ab(N);\n  for (int i = 0; i < N; i++) {\n    ll a, b;\n    cin\
    \ >> a >> b;\n    ab[i] = pl(a, b);\n  }\n  seg.build(ab);\n\n  for (int i = 0;\
    \ i < Q; i++) {\n    int q;\n    cin >> q;\n    if (q == 0) {\n      ll p, c,\
    \ d;\n      cin >> p >> c >> d;\n      seg.update(p, pl(c, d));\n    } else {\n\
    \      ll l, r, x;\n      cin >> l >> r >> x;\n      pl p = seg.get(l, r);\n \
    \     cout << (p.first * x + p.second) % MOD << endl;\n    }\n  }\n}\n"
  dependsOn:
  - structure/segment_tree/segment_tree.cpp
  - common/common.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp.html
title: "\u975E\u53EF\u63DB\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
