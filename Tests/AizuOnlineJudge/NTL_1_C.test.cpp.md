---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/number_theory/my_lcm.cpp
    title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C
    document_title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C
  bundledCode: "#line 1 \"Tests/AizuOnlineJudge/NTL_1_C.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C\"\n/**\n\
    \ * @brief LCM(\u6700\u5C0F\u516C\u500D\u6570)\n */\n\n#include <bits/stdc++.h>\n\
    \n#line 1 \"math/number_theory/my_lcm.cpp\"\n/**\n * @brief LCM(\u6700\u5C0F\u516C\
    \u500D\u6570)\n * @docs docs/math/number_theory/my_lcm.md\n */\n\n#line 7 \"math/number_theory/my_lcm.cpp\"\
    \n\ntemplate <typename T>\nT my_lcm(T a, T b) {\n    return a / gcd(a, b) * b;\n\
    }\n#line 9 \"Tests/AizuOnlineJudge/NTL_1_C.test.cpp\"\n\nusing namespace std;\n\
    typedef long long ll;\n\nint main() {\n    ll N;\n    cin >> N;\n\n    ll lcm\
    \ = 1;\n    for (ll i = 0; i < N; i++) {\n        ll a;\n        cin >> a;\n \
    \       lcm = my_lcm(lcm, a);\n    }\n\n    cout << lcm << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C\"\
    \n/**\n * @brief LCM(\u6700\u5C0F\u516C\u500D\u6570)\n */\n\n#include <bits/stdc++.h>\n\
    \n#include \"../../math/number_theory/my_lcm.cpp\"\n\nusing namespace std;\ntypedef\
    \ long long ll;\n\nint main() {\n    ll N;\n    cin >> N;\n\n    ll lcm = 1;\n\
    \    for (ll i = 0; i < N; i++) {\n        ll a;\n        cin >> a;\n        lcm\
    \ = my_lcm(lcm, a);\n    }\n\n    cout << lcm << endl;\n}\n"
  dependsOn:
  - math/number_theory/my_lcm.cpp
  isVerificationFile: true
  path: Tests/AizuOnlineJudge/NTL_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-03-06 17:59:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/AizuOnlineJudge/NTL_1_C.test.cpp
layout: document
redirect_from:
- /verify/Tests/AizuOnlineJudge/NTL_1_C.test.cpp
- /verify/Tests/AizuOnlineJudge/NTL_1_C.test.cpp.html
title: "LCM(\u6700\u5C0F\u516C\u500D\u6570)"
---
