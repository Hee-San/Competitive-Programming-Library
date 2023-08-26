---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/common.cpp
    title: "\u5171\u901A\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22"
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/bfs.md
    document_title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
    links: []
  bundledCode: "#line 1 \"graph/bfs.cpp\"\n/**\n * @brief BFS (\u5E45\u512A\u5148\u63A2\
    \u7D22)\n * @docs docs/graph/bfs.md\n */\n\n#line 2 \"structure/graph.cpp\"\n\n\
    /**\n * @brief \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n */\n\n#line\
    \ 1 \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\n * @docs docs/common/common.md\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef long long ll;\n\
    typedef vector<int> vi;\ntypedef vector<vi> vvi;\ntypedef vector<ll> vl;\ntypedef\
    \ vector<vl> vvl;\ntypedef vector<bool> vb;\ntypedef vector<string> vs;\n\n#define\
    \ rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define rep2(i, n) for (int i\
    \ = (n)-1; i >= 0; i--)\n#define rep3(i, m, n) for (int i = (m); i < (int)(n);\
    \ i++)\n#line 9 \"structure/graph.cpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct Edge {\n  int from, to;\n  T cost;\n\n  Edge(int from, int to, T\
    \ cost = 1) : from(from), to(to), cost(cost) {}\n};\n\ntemplate <typename T>\n\
    struct Graph {\n  vector<vector<Edge<T>>> edges;\n\n  Graph() = default;\n  Graph(int\
    \ n) : edges(n) {}\n\n  size_t size() { return edges.size(); }\n\n  void add_undirected_edge(int\
    \ from, int to, T cost = 1) {\n    edges[from].emplace_back(from, to, cost);\n\
    \    edges[to].emplace_back(to, from, cost);\n  }\n\n  void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n    edges[from].emplace_back(from, to, cost);\n\
    \  }\n};\n#line 7 \"graph/bfs.cpp\"\n\ntemplate <typename T>\nstruct BFS {\n \
    \ vector<T> dist;\n  vi prev;\n\n  BFS(Graph<T> g, vi starts) {\n    // O(V+E)\n\
    \n    for (auto edge : g.edges)\n      for (auto e : edge)\n        if (e.cost\
    \ != 1) throw runtime_error(\"Not un-weighted graph\");\n\n    dist.resize(g.size(),\
    \ -1);\n    prev.resize(g.size(), -1);\n\n    queue<int> q;  // FIFO\n    for\
    \ (int start : starts) {\n      q.push(start);\n      dist[start] = 0;\n    }\n\
    \    while (!q.empty()) {\n      int from = q.front();\n      q.pop();\n     \
    \ for (Edge<T> edge : g.edges[from]) {\n        if (dist[edge.to] == -1) {\n \
    \         dist[edge.to] = dist[from] + 1;\n          prev[edge.to] = from;\n \
    \         q.push(edge.to);\n        }\n      }\n    }\n  }\n\n  BFS(Graph<T> g,\
    \ int start) : BFS<T>(g, vi({ start })) {}\n\n  vi path(int to) {\n    vi path;\n\
    \    while (to != -1) {\n      path.push_back(to);\n      to = prev[to];\n   \
    \ }\n    reverse(path.begin(), path.end());\n    return path;\n  }\n};\n"
  code: "/**\n * @brief BFS (\u5E45\u512A\u5148\u63A2\u7D22)\n * @docs docs/graph/bfs.md\n\
    \ */\n\n#include \"../structure/graph.cpp\"\n\ntemplate <typename T>\nstruct BFS\
    \ {\n  vector<T> dist;\n  vi prev;\n\n  BFS(Graph<T> g, vi starts) {\n    // O(V+E)\n\
    \n    for (auto edge : g.edges)\n      for (auto e : edge)\n        if (e.cost\
    \ != 1) throw runtime_error(\"Not un-weighted graph\");\n\n    dist.resize(g.size(),\
    \ -1);\n    prev.resize(g.size(), -1);\n\n    queue<int> q;  // FIFO\n    for\
    \ (int start : starts) {\n      q.push(start);\n      dist[start] = 0;\n    }\n\
    \    while (!q.empty()) {\n      int from = q.front();\n      q.pop();\n     \
    \ for (Edge<T> edge : g.edges[from]) {\n        if (dist[edge.to] == -1) {\n \
    \         dist[edge.to] = dist[from] + 1;\n          prev[edge.to] = from;\n \
    \         q.push(edge.to);\n        }\n      }\n    }\n  }\n\n  BFS(Graph<T> g,\
    \ int start) : BFS<T>(g, vi({ start })) {}\n\n  vi path(int to) {\n    vi path;\n\
    \    while (to != -1) {\n      path.push_back(to);\n      to = prev[to];\n   \
    \ }\n    reverse(path.begin(), path.end());\n    return path;\n  }\n};\n"
  dependsOn:
  - structure/graph.cpp
  - common/common.cpp
  isVerificationFile: false
  path: graph/bfs.cpp
  requiredBy: []
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
documentation_of: graph/bfs.cpp
layout: document
redirect_from:
- /library/graph/bfs.cpp
- /library/graph/bfs.cpp.html
title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
---
