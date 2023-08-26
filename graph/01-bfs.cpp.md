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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/01-bfs.md
    document_title: 01-BFS
    links: []
  bundledCode: "#line 1 \"graph/01-bfs.cpp\"\n/**\n * @brief 01-BFS\n * @docs docs/graph/01-bfs.md\n\
    \ */\n\n#line 2 \"structure/graph.cpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\n\
    \ * @docs docs/structure/graph.md\n */\n\n#line 1 \"common/common.cpp\"\n/**\n\
    \ * @brief \u5171\u901A\u8A2D\u5B9A\n * @docs docs/common/common.md\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntypedef long long ll;\ntypedef vector<int>\
    \ vi;\ntypedef vector<vi> vvi;\ntypedef vector<ll> vl;\ntypedef vector<vl> vvl;\n\
    typedef vector<bool> vb;\ntypedef vector<string> vs;\n\n#define rep(i, n) for\
    \ (int i = 0; i < (int)(n); i++)\n#define rep2(i, n) for (int i = (n)-1; i >=\
    \ 0; i--)\n#define rep3(i, m, n) for (int i = (m); i < (int)(n); i++)\n#line 9\
    \ \"structure/graph.cpp\"\nusing namespace std;\n\ntemplate <typename T>\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n\n  Edge(int from, int to, T cost = 1) :\
    \ from(from), to(to), cost(cost) {}\n};\n\ntemplate <typename T>\nstruct Graph\
    \ {\n  vector<vector<Edge<T>>> edges;\n\n  Graph() = default;\n  Graph(int n)\
    \ : edges(n) {}\n\n  size_t size() { return edges.size(); }\n\n  void add_undirected_edge(int\
    \ from, int to, T cost = 1) {\n    edges[from].emplace_back(from, to, cost);\n\
    \    edges[to].emplace_back(to, from, cost);\n  }\n\n  void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n    edges[from].emplace_back(from, to, cost);\n\
    \  }\n};\n#line 7 \"graph/01-bfs.cpp\"\n\ntemplate <typename T>\nstruct ZeroOneBFS\
    \ {\n  vector<T> dist;\n  vi prev;\n\n  ZeroOneBFS(Graph<T> g, vi starts) {\n\
    \    // O(V+E)\n\n    for (auto edge : g.edges)\n      for (auto e : edge)\n \
    \       if (e.cost != 0 && e.cost != 1)\n          throw runtime_error(\"Not 01-weighted\
    \ graph\");\n\n    dist.resize(g.size(), -1);\n    prev.resize(g.size(), -1);\n\
    \n    deque<int> q;  // \u4E21\u7AEF\u30AD\u30E5\u30FC\n    for (int start : starts)\
    \ {\n      q.push_back(start);\n      dist[start] = 0;\n    }\n    while (!q.empty())\
    \ {\n      int from = q.front();\n      q.pop_front();\n      for (Edge<T> edge\
    \ : g.edges[from]) {\n        if (dist[edge.to] == -1) {\n          dist[edge.to]\
    \ = dist[from] + edge.cost;\n          prev[edge.to] = from;\n\n          if (edge.cost\
    \ == 0)\n            q.push_front(edge.to);\n          else\n            q.push_back(edge.to);\n\
    \        }\n      }\n    }\n  }\n\n  ZeroOneBFS(Graph<T> g, int start) : ZeroOneBFS<T>(g,\
    \ vi({ start })) {}\n\n  vi path(int to) {\n    vi path;\n    while (to != -1)\
    \ {\n      path.push_back(to);\n      to = prev[to];\n    }\n    reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n};\n"
  code: "/**\n * @brief 01-BFS\n * @docs docs/graph/01-bfs.md\n */\n\n#include \"\
    ../structure/graph.cpp\"\n\ntemplate <typename T>\nstruct ZeroOneBFS {\n  vector<T>\
    \ dist;\n  vi prev;\n\n  ZeroOneBFS(Graph<T> g, vi starts) {\n    // O(V+E)\n\n\
    \    for (auto edge : g.edges)\n      for (auto e : edge)\n        if (e.cost\
    \ != 0 && e.cost != 1)\n          throw runtime_error(\"Not 01-weighted graph\"\
    );\n\n    dist.resize(g.size(), -1);\n    prev.resize(g.size(), -1);\n\n    deque<int>\
    \ q;  // \u4E21\u7AEF\u30AD\u30E5\u30FC\n    for (int start : starts) {\n    \
    \  q.push_back(start);\n      dist[start] = 0;\n    }\n    while (!q.empty())\
    \ {\n      int from = q.front();\n      q.pop_front();\n      for (Edge<T> edge\
    \ : g.edges[from]) {\n        if (dist[edge.to] == -1) {\n          dist[edge.to]\
    \ = dist[from] + edge.cost;\n          prev[edge.to] = from;\n\n          if (edge.cost\
    \ == 0)\n            q.push_front(edge.to);\n          else\n            q.push_back(edge.to);\n\
    \        }\n      }\n    }\n  }\n\n  ZeroOneBFS(Graph<T> g, int start) : ZeroOneBFS<T>(g,\
    \ vi({ start })) {}\n\n  vi path(int to) {\n    vi path;\n    while (to != -1)\
    \ {\n      path.push_back(to);\n      to = prev[to];\n    }\n    reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n};\n"
  dependsOn:
  - structure/graph.cpp
  - common/common.cpp
  isVerificationFile: false
  path: graph/01-bfs.cpp
  requiredBy: []
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/01-bfs.cpp
layout: document
redirect_from:
- /library/graph/01-bfs.cpp
- /library/graph/01-bfs.cpp.html
title: 01-BFS
---
