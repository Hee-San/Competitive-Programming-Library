---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../graph/dijkstra.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n/**\n\
    \ * @brief \u91CD\u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n\
    \ */\n\n#include <bits/stdc++.h>\n\n#include \"../../graph/dijkstra.cpp\"\n#include\
    \ \"../../structure/graph.cpp\"\n\nusing namespace std;\ntypedef long long ll;\n\
    typedef vector<ll> vi;\n\nint main() {\n    ll N, M, s, t;\n    cin >> N >> M\
    \ >> s >> t;\n\n    Graph<ll> g(N);\n    for (ll i = 0; i < M; i++) {\n      \
    \  ll a, b, c;\n        cin >> a >> b >> c;\n        g.add_directed_edge(a, b,\
    \ c);\n    }\n\n    Dijkstra<ll> dijkstra(g, s);\n    ll dist = dijkstra.dist[t];\n\
    \    vi path = dijkstra.path(t);\n\n    cout << dist << ' ' << path.size() - 1\
    \ << endl;\n    for (ll i = 0; i < path.size() - 1; i++) {\n        cout << path[i]\
    \ << ' ' << path[i + 1] << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Tests/LibraryChecker/Graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Graph/shortest_path.test.cpp
- /verify/Tests/LibraryChecker/Graph/shortest_path.test.cpp.html
title: Tests/LibraryChecker/Graph/shortest_path.test.cpp
---
