---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/01-bfs.cpp
    title: 01-BFS
  - icon: ':x:'
    path: graph/bfs.cpp
    title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
  - icon: ':warning:'
    path: graph/dijkstra.cpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22"
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/structure/graph.md
    document_title: "\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"structure/graph.cpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \n * @docs docs/structure/graph.md\n */\n\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T cost;\n\n    Edge(int from, int\
    \ to, T cost = 1) : from(from), to(to), cost(cost) {}\n};\n\ntemplate <typename\
    \ T>\nstruct Graph {\n    vector<vector<Edge<T> > > edges;\n\n    Graph() = default;\n\
    \    Graph(int n) : edges(n) {}\n\n    size_t size() { return edges.size(); }\n\
    \n    void add_undirected_edge(int from, int to, T cost = 1) {\n        edges[from].emplace_back(from,\
    \ to, cost);\n        edges[to].emplace_back(to, from, cost);\n    }\n\n    void\
    \ add_directed_edge(int from, int to, T cost = 1) {\n        edges[from].emplace_back(from,\
    \ to, cost);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int\
    \ from, to;\n    T cost;\n\n    Edge(int from, int to, T cost = 1) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > edges;\n\n    Graph() = default;\n    Graph(int n) : edges(n) {}\n\n   \
    \ size_t size() { return edges.size(); }\n\n    void add_undirected_edge(int from,\
    \ int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n \
    \       edges[to].emplace_back(to, from, cost);\n    }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/graph.cpp
  requiredBy:
  - graph/dijkstra.cpp
  - graph/01-bfs.cpp
  - graph/bfs.cpp
  timestamp: '2022-04-03 09:48:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
documentation_of: structure/graph.cpp
layout: document
redirect_from:
- /library/structure/graph.cpp
- /library/structure/graph.cpp.html
title: "\u30B0\u30E9\u30D5"
---
