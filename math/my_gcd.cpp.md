---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/my_lcm.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/NTL_1_C.test.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/my_gcd.md
    document_title: "GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/my_gcd.cpp\"\n/**\n * @brief GCD(\u6700\u5927\u516C\
    \u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n *\
    \ @docs docs/math/my_gcd.md\n */\ntemplate <typename T>\nT my_gcd(T a, T b) {\n\
    \  if (a < b) return my_gcd(b, a);\n  T r;\n  while ((r = a % b)) {\n    a = b;\n\
    \    b = r;\n  }\n  return b;\n}\n"
  code: "/**\n * @brief GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n * @docs docs/math/my_gcd.md\n */\ntemplate\
    \ <typename T>\nT my_gcd(T a, T b) {\n  if (a < b) return my_gcd(b, a);\n  T r;\n\
    \  while ((r = a % b)) {\n    a = b;\n    b = r;\n  }\n  return b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/my_gcd.cpp
  requiredBy:
  - math/my_lcm.cpp
  timestamp: '2023-06-11 14:47:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/AizuOnlineJudge/NTL_1_C.test.cpp
documentation_of: math/my_gcd.cpp
layout: document
redirect_from:
- /library/math/my_gcd.cpp
- /library/math/my_gcd.cpp.html
title: "GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
  \u4E92\u9664\u6CD5)"
---
## 概要

2数の最大公約数を求める。

## 使い方

C++17では`std::gcd` を使う。

## 計算量

$O(log(min(a, b)))$
