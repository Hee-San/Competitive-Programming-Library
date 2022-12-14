---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.cpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':question:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    document_title: "\u91CD\u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"Tests/LibraryChecker/Graph/shortest_path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n/**\n * @brief \u91CD\
    \u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n */\n\n#include\
    \ <bits/stdc++.h>\n\n#line 1 \"graph/dijkstra.cpp\"\n/**\n * @brief \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/graph/dijkstra.md\n */\n\n#line\
    \ 2 \"structure/graph.cpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\n * @docs docs/structure/graph.md\n\
    \ */\n\nusing namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int\
    \ from, to;\n    T cost;\n\n    Edge(int from, int to, T cost = 1) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n    vector<vector<Edge<T>\
    \ > > edges;\n\n    Graph() = default;\n    Graph(int n) : edges(n) {}\n\n   \
    \ size_t size() { return edges.size(); }\n\n    void add_undirected_edge(int from,\
    \ int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n \
    \       edges[to].emplace_back(to, from, cost);\n    }\n\n    void add_directed_edge(int\
    \ from, int to, T cost = 1) {\n        edges[from].emplace_back(from, to, cost);\n\
    \    }\n};\n#line 7 \"graph/dijkstra.cpp\"\n\ntemplate <typename T>\nstruct Dijkstra\
    \ {\n    vector<T> dist;\n    vector<int> prev;\n\n    Dijkstra(Graph<T> g, int\
    \ start) {\n        // O(E+VlogV)\n\n        validateNonNegativeWeights(g);\n\n\
    \        dist.resize(g.size(), -1);\n        prev.resize(g.size(), -1);\n\n  \
    \      // \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC, \u30DA\u30A2\u30EA\
    \u30F3\u30B0\u30D2\u30FC\u30D7\n        priority_queue<pair<T, int>, vector<pair<T,\
    \ int> >, greater<pair<T, int> > > q;\n\n        q.push({0, start});\n       \
    \ dist[start] = 0;\n\n        while (!q.empty()) {\n            T cost = q.top().first;\n\
    \            int from = q.top().second;\n            q.pop();\n\n            //\
    \ \u65E2\u306B\u63A2\u7D22\u6E08\u307F\u306A\u3089\u98DB\u3070\u3059\n       \
    \     if (dist[from] < cost) continue;\n\n            for (Edge<T> edge : g.edges[from])\
    \ {\n                T new_cost = cost + edge.cost;\n                if (dist[edge.to]\
    \ > new_cost || dist[edge.to] == -1) {\n                    dist[edge.to] = new_cost;\n\
    \                    prev[edge.to] = from;\n                    q.push({new_cost,\
    \ edge.to});\n                }\n            }\n        }\n    }\n\n    vector<int>\
    \ path(int to) {\n        vector<int> path;\n        while (to != -1) {\n    \
    \        path.push_back(to);\n            to = prev[to];\n        }\n        reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n\n    void validateNonNegativeWeights(Graph<T>\
    \ g) {\n        for (auto edge : g.edges)\n            for (auto e : edge)\n \
    \               if (e.cost < 0)\n                    throw runtime_error(\"Not\
    \ non-negative weights\");\n    }\n};\n#line 10 \"Tests/LibraryChecker/Graph/shortest_path.test.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\ntypedef vector<int> vi;\n\nint\
    \ main() {\n    ll N, M, s, t;\n    cin >> N >> M >> s >> t;\n\n    Graph<ll>\
    \ g(N);\n    for (ll i = 0; i < M; i++) {\n        ll a, b, c;\n        cin >>\
    \ a >> b >> c;\n        g.add_directed_edge(a, b, c);\n    }\n\n    Dijkstra<ll>\
    \ dijkstra(g, s);\n    ll dist = dijkstra.dist[t];\n    vi path = dijkstra.path(t);\n\
    \n    if (dist == -1) {\n        cout << dist << endl;\n        return;\n    }\n\
    \n    cout << dist << ' ' << path.size() - 1 << endl;\n    for (ll i = 0; i <\
    \ path.size() - 1; i++) {\n        cout << path[i] << ' ' << path[i + 1] << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n/**\n\
    \ * @brief \u91CD\u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n\
    \ */\n\n#include <bits/stdc++.h>\n\n#include \"../../../graph/dijkstra.cpp\"\n\
    #include \"../../../structure/graph.cpp\"\n\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef vector<int> vi;\n\nint main() {\n    ll N, M, s, t;\n    cin\
    \ >> N >> M >> s >> t;\n\n    Graph<ll> g(N);\n    for (ll i = 0; i < M; i++)\
    \ {\n        ll a, b, c;\n        cin >> a >> b >> c;\n        g.add_directed_edge(a,\
    \ b, c);\n    }\n\n    Dijkstra<ll> dijkstra(g, s);\n    ll dist = dijkstra.dist[t];\n\
    \    vi path = dijkstra.path(t);\n\n    if (dist == -1) {\n        cout << dist\
    \ << endl;\n        return;\n    }\n\n    cout << dist << ' ' << path.size() -\
    \ 1 << endl;\n    for (ll i = 0; i < path.size() - 1; i++) {\n        cout <<\
    \ path[i] << ' ' << path[i + 1] << endl;\n    }\n}\n"
  dependsOn:
  - graph/dijkstra.cpp
  - structure/graph.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 00:51:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Graph/shortest_path.test.cpp
- /verify/Tests/LibraryChecker/Graph/shortest_path.test.cpp.html
title: "\u91CD\u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
---
