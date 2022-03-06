---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Tests/AizuOnlineJudge/NTL_1_C.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  - icon: ':warning:'
    path: math/number_theory/my_lcm.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/number_theory/my_gcd.md
    document_title: "GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/number_theory/my_gcd.cpp\"\n/**\n * @brief GCD(\u6700\
    \u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5)\n * @docs docs/math/number_theory/my_gcd.md\n */\ntemplate <typename T>\n\
    T my_gcd(T a, T b) {\n    if (a < b) return gcd_func(b, a);\n    T r;\n    while\
    \ ((r = a % b)) {\n        a = b;\n        b = r;\n    }\n    return b;\n}\n"
  code: "/**\n * @brief GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n * @docs docs/math/number_theory/my_gcd.md\n\
    \ */\ntemplate <typename T>\nT my_gcd(T a, T b) {\n    if (a < b) return gcd_func(b,\
    \ a);\n    T r;\n    while ((r = a % b)) {\n        a = b;\n        b = r;\n \
    \   }\n    return b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number_theory/my_gcd.cpp
  requiredBy:
  - math/number_theory/my_lcm.cpp
  - Tests/AizuOnlineJudge/NTL_1_C.cpp
  timestamp: '2022-03-06 17:37:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number_theory/my_gcd.cpp
layout: document
redirect_from:
- /library/math/number_theory/my_gcd.cpp
- /library/math/number_theory/my_gcd.cpp.html
title: "GCD(\u6700\u5927\u516C\u7D04\u6570/\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
  \u4E92\u9664\u6CD5)"
---
