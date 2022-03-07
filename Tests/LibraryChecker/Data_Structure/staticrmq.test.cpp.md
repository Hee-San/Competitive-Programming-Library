---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../structure/segment_tree/segment_tree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ Static RMQ\n */\n\n#include <bits/stdc++.h>\n\n#include \"../../structure/segment_tree/segment_tree.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint\
    \ main() {\n    ll N, Q;\n    cin >> N >> Q;\n\n    vi A(N);\n    for (ll i =\
    \ 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n    SegmentTree<ll> seg(\n\
    \        N, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);\n    seg.build(A);\n\
    \n    for (ll i = 0; i < Q; i++) {\n        ll l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp.html
title: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
---
