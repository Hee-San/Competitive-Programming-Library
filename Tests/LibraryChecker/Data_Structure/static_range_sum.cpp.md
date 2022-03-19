---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/cumulative_sum.cpp
    title: "Cumulative Sum(\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u533A\u9593\u548C"
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/static_range_sum.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n/**\n\
    \ * @brief \u533A\u9593\u548C\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"structure/cumulative_sum.cpp\"\
    \n/**\n * @brief Cumulative Sum(\u7D2F\u7A4D\u548C)\n * @docs docs/structure/cumulative_sum.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct CumulativeSum {\n\
    \    vector<T> cs;\n    CumulativeSum(vector<T> A) {\n        int n = A.size();\n\
    \        cs.resize(n + 1);\n        cs[0] = T();\n        for (int i = 0; i <\
    \ n; i++)\n            cs[i + 1] = cs[i] + A[i];\n    }\n\n    // [l, r)\n   \
    \ T get(int l, int r) { return cs[r] - cs[l]; }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/static_range_sum.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i =\
    \ 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    CumulativeSum<ll> sumA(A);\n\
    \n    for (ll i = 0; i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n\
    \        cout << sumA.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n/**\n\
    \ * @brief \u533A\u9593\u548C\n */\n\n#include <bits/stdc++.h>\n\n#include \"\
    ../../../structure/cumulative_sum.cpp\"\n\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef vector<ll> vi;\n\nint main() {\n    ll N, Q;\n    cin >> N\
    \ >> Q;\n\n    vi A(N);\n    for (ll i = 0; i < N; i++) {\n        cin >> A[i];\n\
    \    }\n\n    CumulativeSum<ll> sumA(A);\n\n    for (ll i = 0; i < Q; i++) {\n\
    \        ll l, r;\n        cin >> l >> r;\n        cout << sumA.get(l, r) << endl;\n\
    \    }\n}\n"
  dependsOn:
  - structure/cumulative_sum.cpp
  isVerificationFile: false
  path: Tests/LibraryChecker/Data_Structure/static_range_sum.cpp
  requiredBy: []
  timestamp: '2022-03-19 12:27:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/static_range_sum.cpp
layout: document
redirect_from:
- /library/Tests/LibraryChecker/Data_Structure/static_range_sum.cpp
- /library/Tests/LibraryChecker/Data_Structure/static_range_sum.cpp.html
title: "\u533A\u9593\u548C"
---
