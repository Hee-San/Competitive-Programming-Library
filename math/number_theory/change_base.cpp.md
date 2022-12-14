---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/number_theory/change_base.md
    document_title: "change base(\u9032\u6570\u5909\u63DB)"
    links: []
  bundledCode: "#line 1 \"math/number_theory/change_base.cpp\"\n/**\n * @brief change\
    \ base(\u9032\u6570\u5909\u63DB)\n * @docs docs/math/number_theory/change_base.md\n\
    \ */\ntemplate <typename T>\nstring base_10_to_N(T n, int base) {\n    if (n ==\
    \ 0) return \"0\";\n    string s = \"\";\n    while (n) {\n        s += (n % base)\
    \ + '0';\n        n /= base;\n    }\n    reverse(s.begin(), s.end());\n    return\
    \ s;\n}\n\ntemplate <typename T>\nT base_N_to_10(string s, int base) {\n    T\
    \ n = 0;\n    for (int i = 0; i < s.size(); i++) {\n        n *= base;\n     \
    \   n += (s[i] - '0');\n    }\n    return n;\n}\n\ntemplate <typename T>\nstring\
    \ change_base(string s, int base_from, int base_to) {\n    T n = base_N_to_10<T>(s,\
    \ base_from);\n    return base_10_to_N<T>(n, base_to);\n}\n"
  code: "/**\n * @brief change base(\u9032\u6570\u5909\u63DB)\n * @docs docs/math/number_theory/change_base.md\n\
    \ */\ntemplate <typename T>\nstring base_10_to_N(T n, int base) {\n    if (n ==\
    \ 0) return \"0\";\n    string s = \"\";\n    while (n) {\n        s += (n % base)\
    \ + '0';\n        n /= base;\n    }\n    reverse(s.begin(), s.end());\n    return\
    \ s;\n}\n\ntemplate <typename T>\nT base_N_to_10(string s, int base) {\n    T\
    \ n = 0;\n    for (int i = 0; i < s.size(); i++) {\n        n *= base;\n     \
    \   n += (s[i] - '0');\n    }\n    return n;\n}\n\ntemplate <typename T>\nstring\
    \ change_base(string s, int base_from, int base_to) {\n    T n = base_N_to_10<T>(s,\
    \ base_from);\n    return base_10_to_N<T>(n, base_to);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number_theory/change_base.cpp
  requiredBy: []
  timestamp: '2022-12-15 00:00:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number_theory/change_base.cpp
layout: document
redirect_from:
- /library/math/number_theory/change_base.cpp
- /library/math/number_theory/change_base.cpp.html
title: "change base(\u9032\u6570\u5909\u63DB)"
---
