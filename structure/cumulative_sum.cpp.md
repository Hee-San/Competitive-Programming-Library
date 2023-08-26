---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/common.cpp
    title: "\u5171\u901A\u8A2D\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
    title: "\u533A\u9593\u548C"
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/structure/cumulative_sum.md
    document_title: "Cumulative Sum(\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 1 \"structure/cumulative_sum.cpp\"\n/**\n * @brief Cumulative\
    \ Sum(\u7D2F\u7A4D\u548C)\n * @docs docs/structure/cumulative_sum.md\n */\n\n\
    #line 1 \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\n * @docs\
    \ docs/common/common.md\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<vi> vvi;\ntypedef\
    \ vector<ll> vl;\ntypedef vector<vl> vvl;\ntypedef vector<bool> vb;\ntypedef vector<string>\
    \ vs;\n\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define rep2(i,\
    \ n) for (int i = (n)-1; i >= 0; i--)\n#define rep3(i, m, n) for (int i = (m);\
    \ i < (int)(n); i++)\n#line 7 \"structure/cumulative_sum.cpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct CumulativeSum {\n  vector<T> cs;\n  CumulativeSum(vector<T>\
    \ A) {\n    int n = A.size();\n    cs.resize(n + 1);\n    cs[0] = T();\n    rep(i,\
    \ n) cs[i + 1] = cs[i] + A[i];\n  }\n\n  // [l, r)\n  T get(int l, int r) { return\
    \ cs[r] - cs[l]; }\n};\n"
  code: "/**\n * @brief Cumulative Sum(\u7D2F\u7A4D\u548C)\n * @docs docs/structure/cumulative_sum.md\n\
    \ */\n\n#include \"../common/common.cpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct CumulativeSum {\n  vector<T> cs;\n  CumulativeSum(vector<T> A) {\n\
    \    int n = A.size();\n    cs.resize(n + 1);\n    cs[0] = T();\n    rep(i, n)\
    \ cs[i + 1] = cs[i] + A[i];\n  }\n\n  // [l, r)\n  T get(int l, int r) { return\
    \ cs[r] - cs[l]; }\n};\n"
  dependsOn:
  - common/common.cpp
  isVerificationFile: false
  path: structure/cumulative_sum.cpp
  requiredBy: []
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
documentation_of: structure/cumulative_sum.cpp
layout: document
redirect_from:
- /library/structure/cumulative_sum.cpp
- /library/structure/cumulative_sum.cpp.html
title: "Cumulative Sum(\u7D2F\u7A4D\u548C)"
---
