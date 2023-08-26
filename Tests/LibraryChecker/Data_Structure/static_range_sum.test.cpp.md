---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/common.cpp
    title: "\u5171\u901A\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: structure/cumulative_sum.cpp
    title: "Cumulative Sum(\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    document_title: "\u533A\u9593\u548C"
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n/**\n\
    \ * @brief \u533A\u9593\u548C\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"structure/cumulative_sum.cpp\"\
    \n/**\n * @brief Cumulative Sum(\u7D2F\u7A4D\u548C)\n * @docs docs/structure/cumulative_sum.md\n\
    \ */\n\n#line 1 \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\
    \n * @docs docs/common/common.md\n */\n\n#line 7 \"common/common.cpp\"\nusing\
    \ namespace std;\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<ll> vl;\ntypedef vector<vl> vvl;\ntypedef vector<bool>\
    \ vb;\ntypedef vector<string> vs;\n\n#define rep(i, n) for (int i = 0; i < (int)(n);\
    \ i++)\n#define rep2(i, n) for (int i = (n)-1; i >= 0; i--)\n#define rep3(i, m,\
    \ n) for (int i = (m); i < (int)(n); i++)\n#line 7 \"structure/cumulative_sum.cpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct CumulativeSum {\n  vector<T>\
    \ cs;\n  CumulativeSum(vector<T> A) {\n    int n = A.size();\n    cs.resize(n\
    \ + 1);\n    cs[0] = T();\n    rep(i, n) cs[i + 1] = cs[i] + A[i];\n  }\n\n  //\
    \ [l, r)\n  T get(int l, int r) { return cs[r] - cs[l]; }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n  ll N, Q;\n  cin >> N >> Q;\n\n  vl\
    \ A(N);\n  for (ll i = 0; i < N; i++) {\n    cin >> A[i];\n  }\n\n  CumulativeSum<ll>\
    \ sumA(A);\n\n  for (ll i = 0; i < Q; i++) {\n    ll l, r;\n    cin >> l >> r;\n\
    \    cout << sumA.get(l, r) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n/**\n\
    \ * @brief \u533A\u9593\u548C\n */\n\n#include <bits/stdc++.h>\n\n#include \"\
    ../../../structure/cumulative_sum.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n  ll N, Q;\n  cin >> N >> Q;\n\n  vl A(N);\n  for (ll i = 0; i < N; i++)\
    \ {\n    cin >> A[i];\n  }\n\n  CumulativeSum<ll> sumA(A);\n\n  for (ll i = 0;\
    \ i < Q; i++) {\n    ll l, r;\n    cin >> l >> r;\n    cout << sumA.get(l, r)\
    \ << endl;\n  }\n}\n"
  dependsOn:
  - structure/cumulative_sum.cpp
  - common/common.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp.html
title: "\u533A\u9593\u548C"
---
