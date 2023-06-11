---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.cpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
  bundledCode: "#line 1 \"Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n/**\n * @brief \u7D20\
    \u6570\u5224\u5B9A\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"math/is_prime.cpp\"\
    \n/**\n * @brief \u7D20\u6570\u5224\u5B9A\n * @docs docs/math/is_prime.md\n */\n\
    \ntypedef long long ll;\n\nbool is_prime(ll n) {\n  if (n <= 1) return false;\n\
    \  for (ll i = 2; i * i <= n; ++i) {\n    if (n % i == 0) return false;\n  }\n\
    \  return true;\n}\n#line 9 \"Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp\"\n\nusing\
    \ namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint main()\
    \ {\n    ll n;\n    cin >> n;\n\n    ll ans = 0;\n    for(ll i = 0; i < n; i++)\
    \ {\n        ll x;\n        cin >> x;\n        if(is_prime(x)) ans++;\n    }\n\
    \n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n\
    /**\n * @brief \u7D20\u6570\u5224\u5B9A\n */\n\n#include <bits/stdc++.h>\n\n#include\
    \ \"../../math/is_prime.cpp\"\n\nusing namespace std;\ntypedef long long ll;\n\
    typedef vector<ll> vi;\n\nint main() {\n    ll n;\n    cin >> n;\n\n    ll ans\
    \ = 0;\n    for(ll i = 0; i < n; i++) {\n        ll x;\n        cin >> x;\n  \
    \      if(is_prime(x)) ans++;\n    }\n\n    cout << ans << endl;\n}\n"
  dependsOn:
  - math/is_prime.cpp
  isVerificationFile: true
  path: Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-06-11 14:41:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp
- /verify/Tests/AizuOnlineJudge/ALDS1_1_C.test.cpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
