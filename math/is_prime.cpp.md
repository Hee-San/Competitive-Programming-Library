---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/is_prime.md
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"math/is_prime.cpp\"\n/**\n * @brief \u7D20\u6570\u5224\u5B9A\
    \n * @docs docs/math/is_prime.md\n */\n\ntypedef long long ll;\n\nbool is_prime(ll\
    \ n) {\n  if (n <= 1) return false;\n  for (ll i = 2; i * i <= n; ++i) {\n   \
    \ if (n % i == 0) return false;\n  }\n  return true;\n}\n"
  code: "/**\n * @brief \u7D20\u6570\u5224\u5B9A\n * @docs docs/math/is_prime.md\n\
    \ */\n\ntypedef long long ll;\n\nbool is_prime(ll n) {\n  if (n <= 1) return false;\n\
    \  for (ll i = 2; i * i <= n; ++i) {\n    if (n % i == 0) return false;\n  }\n\
    \  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.cpp
  requiredBy: []
  timestamp: '2023-06-11 14:41:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp
documentation_of: math/is_prime.cpp
layout: document
redirect_from:
- /library/math/is_prime.cpp
- /library/math/is_prime.cpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
