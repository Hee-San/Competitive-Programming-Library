---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22"
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/bfs.md
    document_title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
    links: []
  bundledCode: "#line 1 \"graph/bfs.cpp\"\n/**\n * @brief BFS (\u5E45\u512A\u5148\u63A2\
    \u7D22)\n * @docs docs/graph/bfs.md\n */\n\n#line 2 \"structure/graph.cpp\"\n\n\
    /**\n * @brief \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n */\n\nusing\
    \ namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T cosst;\n\n    Edge(int from, int to, T cosst = 1) : from(from), to(to),\
    \ cosst(cosst) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > edges;\n\n    Graph() = default;\n    Graph(int n) : edges(n) {}\n\n   \
    \ size_t size() { return edges.size(); }\n\n    void add_edge(int from, int to,\
    \ T cosst = 1) {\n        edges[from].emplace_back(from, to, cosst);\n       \
    \ edges[to].emplace_back(to, from, cosst);\n    }\n\n    void add_directed_edge(int\
    \ from, int to, T cosst = 1) {\n        edges[from].emplace_back(from, to, cosst);\n\
    \    }\n};\n#line 7 \"graph/bfs.cpp\"\n\ntemplate <typename T>\nstruct BFS {\n\
    \    vector<T> dist;\n    vector<int> prev;\n\n    BFS(Graph<T> g, int start)\
    \ {\n        // \u91CD\u307F\u306A\u3057\u30B0\u30E9\u30D5\u304B\u30C1\u30A7\u30C3\
    \u30AF\n        for (auto& e : g.edges) {\n            if (e.size() != 1) {\n\
    \                throw runtime_error(\"Not unweighted graph\");\n            }\n\
    \        }\n\n        dist.resize(g.size(), -1);\n        prev.resize(g.size(),\
    \ -1);\n\n        queue<int> q;\n        q.push(start);\n        dist[start] =\
    \ 0;\n        while (!q.empty()) {\n            int from = q.front();\n      \
    \      q.pop();\n            for (Edge<T> edge : g.edges[from]) {\n          \
    \      if (dist[edge.to] == -1) {\n                    dist[edge.to] = dist[from]\
    \ + 1;\n                    prev[edge.to] = from;\n                    q.push(edge.to);\n\
    \                }\n            }\n        }\n    }\n\n    vector<int> path(int\
    \ to) {\n        vector<int> path;\n        while (to != -1) {\n            path.push_back(to);\n\
    \            to = prev[to];\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n};\n"
  code: "/**\n * @brief BFS (\u5E45\u512A\u5148\u63A2\u7D22)\n * @docs docs/graph/bfs.md\n\
    \ */\n\n#include \"../structure/graph.cpp\"\n\ntemplate <typename T>\nstruct BFS\
    \ {\n    vector<T> dist;\n    vector<int> prev;\n\n    BFS(Graph<T> g, int start)\
    \ {\n        // \u91CD\u307F\u306A\u3057\u30B0\u30E9\u30D5\u304B\u30C1\u30A7\u30C3\
    \u30AF\n        for (auto& e : g.edges) {\n            if (e.size() != 1) {\n\
    \                throw runtime_error(\"Not unweighted graph\");\n            }\n\
    \        }\n\n        dist.resize(g.size(), -1);\n        prev.resize(g.size(),\
    \ -1);\n\n        queue<int> q;\n        q.push(start);\n        dist[start] =\
    \ 0;\n        while (!q.empty()) {\n            int from = q.front();\n      \
    \      q.pop();\n            for (Edge<T> edge : g.edges[from]) {\n          \
    \      if (dist[edge.to] == -1) {\n                    dist[edge.to] = dist[from]\
    \ + 1;\n                    prev[edge.to] = from;\n                    q.push(edge.to);\n\
    \                }\n            }\n        }\n    }\n\n    vector<int> path(int\
    \ to) {\n        vector<int> path;\n        while (to != -1) {\n            path.push_back(to);\n\
    \            to = prev[to];\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n};\n"
  dependsOn:
  - structure/graph.cpp
  isVerificationFile: false
  path: graph/bfs.cpp
  requiredBy: []
  timestamp: '2022-03-27 16:41:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
documentation_of: graph/bfs.cpp
layout: document
redirect_from:
- /library/graph/bfs.cpp
- /library/graph/bfs.cpp.html
title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
---
