---
data:
  _extendedDependsOn: []
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
    using namespace std;\n\ntemplate <typename T>\nstruct CumulativeSum {\n    vector<T>\
    \ cs;\n    CumulativeSum(vector<T> A) {\n        int n = A.size();\n        cs.resize(n\
    \ + 1);\n        cs[0] = T();\n        for (int i = 0; i < n; i++)\n         \
    \   cs[i + 1] = cs[i] + A[i];\n    }\n\n    // [l, r)\n    T get(int l, int r)\
    \ { return cs[r] - cs[l]; }\n};\n"
  code: "/**\n * @brief Cumulative Sum(\u7D2F\u7A4D\u548C)\n * @docs docs/structure/cumulative_sum.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct CumulativeSum {\n\
    \    vector<T> cs;\n    CumulativeSum(vector<T> A) {\n        int n = A.size();\n\
    \        cs.resize(n + 1);\n        cs[0] = T();\n        for (int i = 0; i <\
    \ n; i++)\n            cs[i + 1] = cs[i] + A[i];\n    }\n\n    // [l, r)\n   \
    \ T get(int l, int r) { return cs[r] - cs[l]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/cumulative_sum.cpp
  requiredBy: []
  timestamp: '2022-03-19 12:27:26+09:00'
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
