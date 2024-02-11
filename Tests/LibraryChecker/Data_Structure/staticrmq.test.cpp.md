---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/common.cpp
    title: "\u5171\u901A\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: structure/segment_tree/segment_tree.cpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\
      \u65B0\u30FB\u533A\u9593\u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ \u533A\u9593\u306E\u6700\u5C0F\u5024\n */\n\n#include <bits/stdc++.h>\n\n#line\
    \ 1 \"structure/segment_tree/segment_tree.cpp\"\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728, \u4E00\u70B9\u3092\u66F4\u65B0\u30FB\u533A\u9593\
    \u306E\u6F14\u7B97\u7D50\u679C\u3092\u53D6\u5F97)\n * @docs docs/structure/segment_tree/segment_tree.md\n\
    \ */\n\n#line 1 \"common/common.cpp\"\n/**\n * @brief \u5171\u901A\u8A2D\u5B9A\
    \n * @docs docs/common/common.md\n */\n\n#line 7 \"common/common.cpp\"\nusing\
    \ namespace std;\n\ntypedef long long ll;\ntypedef vector<int> vi;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<ll> vl;\ntypedef vector<vl> vvl;\ntypedef vector<bool>\
    \ vb;\ntypedef vector<string> vs;\n\n#define rep(i, n) for (int i = 0; i < (int)(n);\
    \ i++)\n#define rep2(i, n) for (int i = (n)-1; i >= 0; i--)\n#define rep3(i, m,\
    \ n) for (int i = (m); i < (int)(n); i++)\n#line 7 \"structure/segment_tree/segment_tree.cpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct SegmentTree {\n  typedef\
    \ T(*F)(T, T);\n  int n;\n  vector<T> seg;\n  F function;\n  T identity;\n\n \
    \ SegmentTree(int n, F function, T identity)\n    : n(n), function(function),\
    \ identity(identity) {\n    seg.assign(2 * n, identity);\n  }\n\n  void build(vector<T>\
    \ v) {\n    assert(n == (int)v.size());\n    rep(i, n) seg[n + i] = v[i];\n  \
    \  rep2(i, n) seg[i] = function(seg[2 * i], seg[2 * i + 1]);\n  }\n\n  void update(int\
    \ x, T val) {\n    x += n;\n    seg[x] = val;\n    while (x > 1) {\n      x =\
    \ x / 2;\n      seg[x] = function(seg[2 * x], seg[2 * x + 1]);\n    }\n  }\n\n\
    \  T get(int x) {\n    x += n;\n    return seg[x];\n  }\n\n  T get(int l, int\
    \ r) {\n    T left = identity;\n    T right = identity;\n    for (l += n, r +=\
    \ n; l < r; l /= 2, r /= 2) {\n      if (l % 2) left = function(left, seg[l++]);\n\
    \      if (r % 2) right = function(seg[--r], right);\n    }\n    return function(left,\
    \ right);\n  }\n\n  int getLevel(int index) {\n    return floor(log2(index));\n\
    \  }\n\n  void display() {\n    // \u6700\u5927\u306E\u6841\u6570\n    int digit\
    \ = 1;\n    for (T x : seg) {\n      digit = max(digit, (int)to_string(x).size());\n\
    \    }\n\n    // \u8868\u793A\u7528\u306E\u5024\u3092\u4F5C\u6210\n    int depth\
    \ = getLevel(2 * n);\n    vector<vs> rangeStrs(0), valStrs(0);\n    rep(i, depth)\
    \ {\n      auto [start, end] = getIndexRangeOfLevel(i);\n      vs subRangeStrs(0),\
    \ subValStrs(0);\n      rep3(j, start, end) {\n        subRangeStrs.push_back(displayNodeRange(j));\n\
    \        subValStrs.push_back(to_string(seg[j]));\n      }\n      rangeStrs.push_back(subRangeStrs);\n\
    \      valStrs.push_back(subValStrs);\n    }\n\n    // \u30BB\u30EB\u306E\u5E45\
    \u3092\u8A08\u7B97\n    int cellWidth = 0;\n    rep(i, depth) {\n      int m =\
    \ rangeStrs[i].size();\n      rep(j, m) {\n        cellWidth = max(cellWidth,\
    \ (int)rangeStrs[i][j].size() * m / n);\n        cellWidth = max(cellWidth, (int)valStrs[i][j].size()\
    \ * m / n);\n      }\n    }\n\n    // \u8868\u793A\n    string sepate = displaySepate(cellWidth);\n\
    \    int witdh = sepate.size();\n    rep(i, depth) {\n      cout << sepate <<\
    \ endl;\n      cout << displayNodes(witdh, rangeStrs[i]) << endl;\n      cout\
    \ << displayNodes(witdh, valStrs[i]) << endl;\n    }\n    cout << sepate << endl;\n\
    \  }\n\nprivate:\n  pair<int, int> getIndexRangeOfLevel(int level) {\n    int\
    \ start = pow(2, level);\n    int end = start * 2;\n    return make_pair(start,\
    \ end);\n  }\n\n  pair<int, int> getValRangeOfNode(int index) {\n    int level\
    \ = getLevel(index);\n    int levelStart = pow(2, level);\n    int indexInLevel\
    \ = index - levelStart;\n    int rangeSize = n / pow(2, level);\n    int start\
    \ = indexInLevel * rangeSize;\n    int end = start + rangeSize;\n    return make_pair(start,\
    \ end);\n  }\n\n  string displaySepate(int cellWidth) {\n    string res = \"|\"\
    ;\n    rep(i, n) {\n      rep(j, cellWidth) res += \"-\";\n      if (i != n -\
    \ 1) res += \"-\";\n    }\n    res += \"|\";\n    return res;\n  }\n\n  string\
    \ displayNodes(int witdh, vector<string> nodes) {\n    string res = \"|\";\n \
    \   int cellWidth = (witdh - 1) / nodes.size() - 1;\n    rep(i, nodes.size())\
    \ {\n      res += displayCenter(cellWidth, nodes[i]);\n      res += \"|\";\n \
    \   }\n    return res;\n  }\n\n  string displayNodeRange(int index) {\n    if\
    \ (index == 0) return \"\"; // 0\u756A\u76EE\u306E\u30CE\u30FC\u30C9\u306F\u5B58\
    \u5728\u3057\u306A\u3044\n    auto [start, end] = getValRangeOfNode(index);\n\
    \    if (start + 1 == end) return to_string(start);\n    return \"[\" + to_string(start)\
    \ + \",\" + to_string(end) + \")\";\n  }\n\n  string displayCenter(int l, string\
    \ s) {\n    int space = l - s.size();\n    int padRight = space / 2;\n    int\
    \ padLeft = space - padRight;\n    string res = \"\";\n    rep(i, padLeft) res\
    \ += \" \";\n    res += s;\n    rep(i, padRight) res += \" \";\n    return res;\n\
    \  }\n};\n#line 9 \"Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp\"\n\
    \nusing namespace std;\n\nint main() {\n  int N, Q;\n  cin >> N >> Q;\n\n  vi\
    \ A(N);\n  rep(i, N) cin >> A[i];\n\n  SegmentTree<int> seg(\n    N, [](int a,\
    \ int b) { return min(a, b); }, INT_MAX);\n  seg.build(A);\n\n  rep(i, Q) {\n\
    \    ll l, r;\n    cin >> l >> r;\n    cout << seg.get(l, r) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n/**\n * @brief\
    \ \u533A\u9593\u306E\u6700\u5C0F\u5024\n */\n\n#include <bits/stdc++.h>\n\n#include\
    \ \"../../../structure/segment_tree/segment_tree.cpp\"\n\nusing namespace std;\n\
    \nint main() {\n  int N, Q;\n  cin >> N >> Q;\n\n  vi A(N);\n  rep(i, N) cin >>\
    \ A[i];\n\n  SegmentTree<int> seg(\n    N, [](int a, int b) { return min(a, b);\
    \ }, INT_MAX);\n  seg.build(A);\n\n  rep(i, Q) {\n    ll l, r;\n    cin >> l >>\
    \ r;\n    cout << seg.get(l, r) << endl;\n  }\n}\n"
  dependsOn:
  - structure/segment_tree/segment_tree.cpp
  - common/common.cpp
  isVerificationFile: true
  path: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2024-02-11 17:37:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp
- /verify/Tests/LibraryChecker/Data_Structure/staticrmq.test.cpp.html
title: "\u533A\u9593\u306E\u6700\u5C0F\u5024"
---
