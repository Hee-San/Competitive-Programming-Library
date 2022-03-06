---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number_theory/my_gcd.cpp
    title: "GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
      \u306E\u4E92\u9664\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/0005.test.cpp
    title: "\u6700\u5927\u516C\u7D04\u6570\u3068\u6700\u5C0F\u516C\u500D\u6570"
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/NTL_1_C.test.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/number_theory/my_lcm.md
    document_title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
    links: []
  bundledCode: "#line 1 \"math/number_theory/my_lcm.cpp\"\n/**\n * @brief LCM(\u6700\
    \u5C0F\u516C\u500D\u6570)\n * @docs docs/math/number_theory/my_lcm.md\n */\n\n\
    #line 1 \"math/number_theory/my_gcd.cpp\"\n/**\n * @brief GCD(\u6700\u5927\u516C\
    \u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n *\
    \ @docs docs/math/number_theory/my_gcd.md\n */\ntemplate <typename T>\nT my_gcd(T\
    \ a, T b) {\n    if (a < b) return my_gcd(b, a);\n    T r;\n    while ((r = a\
    \ % b)) {\n        a = b;\n        b = r;\n    }\n    return b;\n}\n#line 7 \"\
    math/number_theory/my_lcm.cpp\"\n\ntemplate <typename T>\nT my_lcm(T a, T b) {\n\
    \    return a / my_gcd(a, b) * b;\n}\n"
  code: "/**\n * @brief LCM(\u6700\u5C0F\u516C\u500D\u6570)\n * @docs docs/math/number_theory/my_lcm.md\n\
    \ */\n\n#include \"../../math/number_theory/my_gcd.cpp\"\n\ntemplate <typename\
    \ T>\nT my_lcm(T a, T b) {\n    return a / my_gcd(a, b) * b;\n}\n"
  dependsOn:
  - math/number_theory/my_gcd.cpp
  isVerificationFile: false
  path: math/number_theory/my_lcm.cpp
  requiredBy: []
  timestamp: '2022-03-06 18:11:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
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