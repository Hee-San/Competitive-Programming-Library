---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/01-bfs.cpp
    title: 01-BFS
  - icon: ':heavy_check_mark:'
    path: graph/bfs.cpp
    title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: structure/cumulative_sum.cpp
    title: "Cumulative Sum(\u7D2F\u7A4D\u548C)"
  - icon: ':heavy_check_mark:'
    path: structure/graph.cpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: structure/segment_tree/segment_tree.cpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\
      \u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/DSL_2_A.test.cpp
    title: "\u533A\u9593\u306E\u6700\u5C0F\u5024\u30FB\u4E00\u70B9\u66F4\u65B0 Range\
      \ Minimum Query (RMQ)"
  - icon: ':heavy_check_mark:'
    path: Tests/AizuOnlineJudge/DSL_2_B.test.cpp
    title: "\u533A\u9593\u306E\u548C\u30FB\u4E00\u70B9\u52A0\u7B97 Range Sum Query\
      \ (RSQ)"
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp
    title: "\u975E\u53EF\u63DB\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
    title: "\u533A\u9593\u548C"
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
    title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
  - icon: ':heavy_check_mark:'
    path: Tests/LibraryChecker/Graph/shortest_path.test.cpp
    title: "\u91CD\u307F\u4ED8\u304D\u3001\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/common/common.md
    document_title: "\u5171\u901A\u8A2D\u5B9A"
    links: []
  bundledCode: "#line 1 \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\
    \n * @docs docs/common/common.md\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<vi> vvi;\n\
    typedef vector<ll> vl;\ntypedef vector<vl> vvl;\ntypedef vector<bool> vb;\ntypedef\
    \ vector<string> vs;\n\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n\
    #define rep2(i, n) for (int i = (n)-1; i >= 0; i--)\n#define rep3(i, m, n) for\
    \ (int i = (m); i < (int)(n); i++)\n"
  code: "/**\n * @brief \u5171\u901A\u8A2D\u5B9A\n * @docs docs/common/common.md\n\
    \ */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntypedef long long ll;\n\
    typedef vector<int> vi;\ntypedef vector<vi> vvi;\ntypedef vector<ll> vl;\ntypedef\
    \ vector<vl> vvl;\ntypedef vector<bool> vb;\ntypedef vector<string> vs;\n\n#define\
    \ rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define rep2(i, n) for (int i\
    \ = (n)-1; i >= 0; i--)\n#define rep3(i, m, n) for (int i = (m); i < (int)(n);\
    \ i++)\n"
  dependsOn: []
  isVerificationFile: false
  path: common/common.cpp
  requiredBy:
  - structure/graph.cpp
  - structure/segment_tree/segment_tree.cpp
  - structure/cumulative_sum.cpp
  - graph/bfs.cpp
  - graph/01-bfs.cpp
  - graph/dijkstra.cpp
  timestamp: '2023-08-26 20:40:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  - Tests/LibraryChecker/Data_Structure/point_set_range_composite.test.cpp
  - Tests/LibraryChecker/Data_Structure/static_range_sum.test.cpp
  - Tests/LibraryChecker/Graph/shortest_path.test.cpp
  - Tests/AizuOnlineJudge/DSL_2_A.test.cpp
  - Tests/AizuOnlineJudge/DSL_2_B.test.cpp
  - Tests/AizuOnlineJudge/ALDS1_11_C.test.cpp
documentation_of: common/common.cpp
layout: document
redirect_from:
- /library/common/common.cpp
- /library/common/common.cpp.html
title: "\u5171\u901A\u8A2D\u5B9A"
---
