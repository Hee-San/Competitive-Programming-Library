---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/0005.test.cpp
    title: "\u6700\u5927\u516C\u7D04\u6570\u3068\u6700\u5C0F\u516C\u500D\u6570"
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/NTL_1_C.test.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/number_theory/my_lcm.md
    document_title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
    links: []
  bundledCode: "#line 1 \"math/number_theory/my_lcm.cpp\"\n/**\n * @brief LCM(\u6700\
    \u5C0F\u516C\u500D\u6570)\n * @docs docs/math/number_theory/my_lcm.md\n */\n\n\
    #include <bits/stdc++.h>\n\ntemplate <typename T>\nT my_lcm(T a, T b) {\n    return\
    \ a / gcd(a, b) * b;\n}\n"
  code: "/**\n * @brief LCM(\u6700\u5C0F\u516C\u500D\u6570)\n * @docs docs/math/number_theory/my_lcm.md\n\
    \ */\n\n#include <bits/stdc++.h>\n\ntemplate <typename T>\nT my_lcm(T a, T b)\
    \ {\n    return a / gcd(a, b) * b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number_theory/my_lcm.cpp
  requiredBy: []
  timestamp: '2022-03-06 17:59:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Tests/AizuOnlineJudge/0005.test.cpp
  - Tests/AizuOnlineJudge/NTL_1_C.test.cpp
documentation_of: math/number_theory/my_lcm.cpp
layout: document
redirect_from:
- /library/math/number_theory/my_lcm.cpp
- /library/math/number_theory/my_lcm.cpp.html
title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
---
## 概要

2数の最小公倍数を求める。

## 使い方

C++17では`std::lcm` を使う。

## 計算量

$O(log(min(a, b)))$