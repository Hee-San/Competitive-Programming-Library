---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5\n * @docs docs/graph/dijkstra.md\n */\n\n#line 2 \"structure/graph.cpp\"\
    \n\n/**\n * @brief \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n */\n\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n\n    Edge(int from, int to, T cost = 1) : from(from), to(to),\
    \ cost(cost) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > edges;\n\n    Graph() = default;\n    Graph(int n) : edges(n) {}\n\n   \
    \ size_t size() { return edges.size(); }\n\n    void add_undirected_edge(int from,\
    \ int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n \
    \       edges[to].emplace_back(to, from, cost);\n    }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n\
    \    }\n};\n#line 7 \"graph/dijkstra.cpp\"\n\ntemplate <typename T>\nstruct Dijkstra\
    \ {\n    vector<T> dist;\n    vector<int> prev;\n\n    Dijkstra(Graph<T> g, vector<int>\
    \ starts) {\n        // O(E+VlogV)\n\n        for (auto edge : g.edges)\n    \
    \        for (auto e : edge)\n                if (e.cost < 0)\n              \
    \      throw runtime_error(\"Not non-negative weights\");\n\n        dist.resize(g.size(),\
    \ -1);\n        prev.resize(g.size(), -1);\n\n        priority_queue<int> q; \
    \ // \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC, \u30DA\u30A2\u30EA\u30F3\
    \u30B0\u30D2\u30FC\u30D7\n        for (int start : starts) {\n            q.push(start);\n\
    \            dist[start] = 0;\n        }\n        while (!q.empty()) {\n     \
    \       int from = q.top();\n            q.pop();\n            for (Edge<T> edge\
    \ : g.edges[from]) {\n                if (dist[edge.to] == -1) {\n           \
    \         dist[edge.to] = dist[from] + edge.cost;\n                    prev[edge.to]\
    \ = from;\n                    q.push(edge.to);\n                }\n         \
    \   }\n        }\n    }\n\n    Dijkstra(Graph<T> g, int start) : Dijkstra(g, {start})\
    \ {}\n\n    vector<int> path(int to) {\n        vector<int> path;\n        while\
    \ (to != -1) {\n            path.push_back(to);\n            to = prev[to];\n\
    \        }\n        reverse(path.begin(), path.end());\n        return path;\n\
    \    }\n};\n"
  code: "/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/graph/dijkstra.md\n\
    \ */\n\n#include \"../structure/graph.cpp\"\n\ntemplate <typename T>\nstruct Dijkstra\
    \ {\n    vector<T> dist;\n    vector<int> prev;\n\n    Dijkstra(Graph<T> g, vector<int>\
    \ starts) {\n        // O(E+VlogV)\n\n        for (auto edge : g.edges)\n    \
    \        for (auto e : edge)\n                if (e.cost < 0)\n              \
    \      throw runtime_error(\"Not non-negative weights\");\n\n        dist.resize(g.size(),\
    \ -1);\n        prev.resize(g.size(), -1);\n\n        priority_queue<int> q; \
    \ // \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC, \u30DA\u30A2\u30EA\u30F3\
    \u30B0\u30D2\u30FC\u30D7\n        for (int start : starts) {\n            q.push(start);\n\
    \            dist[start] = 0;\n        }\n        while (!q.empty()) {\n     \
    \       int from = q.top();\n            q.pop();\n            for (Edge<T> edge\
    \ : g.edges[from]) {\n                if (dist[edge.to] == -1) {\n           \
    \         dist[edge.to] = dist[from] + edge.cost;\n                    prev[edge.to]\
    \ = from;\n                    q.push(edge.to);\n                }\n         \
    \   }\n        }\n    }\n\n    Dijkstra(Graph<T> g, int start) : Dijkstra(g, {start})\
    \ {}\n\n    vector<int> path(int to) {\n        vector<int> path;\n        while\
    \ (to != -1) {\n            path.push_back(to);\n            to = prev[to];\n\
    \        }\n        reverse(path.begin(), path.end());\n        return path;\n\
    \    }\n};\n"
  dependsOn:
  - structure/graph.cpp
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-04-03 10:04:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
