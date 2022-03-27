---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/bfs.cpp
    title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
  - icon: ':x:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':x:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C
    document_title: "\u5E45\u512A\u5148\u63A2\u7D22"
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C
  bundledCode: "#line 1 \"Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C\"\n/**\n * @brief \u5E45\
    \u512A\u5148\u63A2\u7D22\n */\n\n#include <bits/stdc++.h>\n\n#line 1 \"graph/bfs.cpp\"\
    \n/**\n * @brief BFS (\u5E45\u512A\u5148\u63A2\u7D22)\n * @docs docs/graph/bfs.md\n\
    \ */\n\n#line 1 \"structure/graph.cpp\"\n/**\n * @brief \u30B0\u30E9\u30D5\n *\
    \ @docs docs/structure/graph.md\n */\n\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T cosst;\n\n    Edge(int from, int\
    \ to, T cosst = 1) : from(from), to(to), cosst(cosst) {}\n};\n\ntemplate <typename\
    \ T>\nstruct Graph {\n    vector<vector<Edge> > edges;\n\n    Graph() = default;\n\
    \    Graph(int n) : edges(n) {}\n\n    size_t size() const { return edges.size();\
    \ }\n\n    void add_edge(int from, int to, T cosst = 1) {\n        edges[from].emplace_back(from,\
    \ to, cosst);\n        edges[to].emplace_back(to, from, cosst);\n    }\n\n   \
    \ void add_directed_edge(int from, int to, T cosst = 1) {\n        edges[from].emplace_back(from,\
    \ to, cosst);\n    }\n};\n#line 7 \"graph/bfs.cpp\"\n\ntemplate <typename T>\n\
    struct BFS {\n    vector<T> dist;\n    vector<int> prev;\n\n    BFS(Graph<T> g,\
    \ int start) {\n        // \u91CD\u307F\u306A\u3057\u30B0\u30E9\u30D5\u304B\u30C1\
    \u30A7\u30C3\u30AF\n        for (auto& e : g.edges) {\n            if (e.size()\
    \ != 1) {\n                throw runtime_error(\"Not unweighted graph\");\n  \
    \          }\n        }\n\n        dist.resize(g.size(), -1);\n        prev.resize(g.size(),\
    \ -1);\n\n        queue<int> q;\n        q.push(start);\n        dist[start] =\
    \ 0;\n        while (!q.empty()) {\n            int from = q.front();\n      \
    \      q.pop();\n            for (Edge<T> edge : g.edges[from]) {\n          \
    \      if (dist[edge.to] == -1) {\n                    dist[edge.to] = dist[from]\
    \ + 1;\n                    prev[edge.to] = from;\n                    q.push(edge.to);\n\
    \                }\n            }\n        }\n    }\n\n    vector<int> path(int\
    \ to) {\n        vector<int> path;\n        while (to != -1) {\n            path.push_back(to);\n\
    \            to = prev[to];\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n};\n#line 1 \"structure/graph.cpp\"\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n */\n\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cosst;\n\
    \n    Edge(int from, int to, T cosst = 1) : from(from), to(to), cosst(cosst) {}\n\
    };\n\ntemplate <typename T>\nstruct Graph {\n    vector<vector<Edge> > edges;\n\
    \n    Graph() = default;\n    Graph(int n) : edges(n) {}\n\n    size_t size()\
    \ const { return edges.size(); }\n\n    void add_edge(int from, int to, T cosst\
    \ = 1) {\n        edges[from].emplace_back(from, to, cosst);\n        edges[to].emplace_back(to,\
    \ from, cosst);\n    }\n\n    void add_directed_edge(int from, int to, T cosst\
    \ = 1) {\n        edges[from].emplace_back(from, to, cosst);\n    }\n};\n#line\
    \ 10 \"Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp\"\n\nusing namespace std;\ntypedef\
    \ long long ll;\ntypedef vector<ll> vi;\n\nint main() {\n    ll n;\n    cin >>\
    \ n;\n\n    Graph<ll> g(n);\n    for (ll i = 0; i < n; i++) {\n        ll u, k;\n\
    \        cin >> u >> k;\n        for (ll j = 0; j < k; j++) {\n            ll\
    \ v;\n            cin >> v;\n            g.add_edge(i, --v);\n        }\n    }\n\
    \n    BFS<ll> bfs(g, 0);\n\n    for (ll i = 0; i < n; i++) {\n        cout <<\
    \ i + 1 << \" \" << bfs.dist[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C\"\n\
    /**\n * @brief \u5E45\u512A\u5148\u63A2\u7D22\n */\n\n#include <bits/stdc++.h>\n\
    \n#include \"../../graph/bfs.cpp\"\n#include \"../../structure/graph.cpp\"\n\n\
    using namespace std;\ntypedef long long ll;\ntypedef vector<ll> vi;\n\nint main()\
    \ {\n    ll n;\n    cin >> n;\n\n    Graph<ll> g(n);\n    for (ll i = 0; i < n;\
    \ i++) {\n        ll u, k;\n        cin >> u >> k;\n        for (ll j = 0; j <\
    \ k; j++) {\n            ll v;\n            cin >> v;\n            g.add_edge(i,\
    \ --v);\n        }\n    }\n\n    BFS<ll> bfs(g, 0);\n\n    for (ll i = 0; i <\
    \ n; i++) {\n        cout << i + 1 << \" \" << bfs.dist[i] << endl;\n    }\n}\n"
  dependsOn:
  - graph/bfs.cpp
  - structure/graph.cpp
  - structure/graph.cpp
  isVerificationFile: true
  path: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2022-03-27 16:21:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
- /verify/Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp.html
title: "\u5E45\u512A\u5148\u63A2\u7D22"
---
