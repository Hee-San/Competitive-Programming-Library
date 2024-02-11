/**
 * @brief Segment Tree(セグメント木, 一点を更新・区間の演算結果を取得)
 * @docs docs/structure/segment_tree/segment_tree_v1.md
 */

#include "../../common/common.cpp"
using namespace std;

template <typename T>
struct SegmentTree {
  typedef T(*F)(T, T);
  int n;
  vector<T> seg;
  F function;
  T identity;

  SegmentTree(int n, F function, T identity)
    : n(n), function(function), identity(identity) {
    seg.assign(2 * n, identity);
  }

  void build(vector<T> v) {
    assert(n == (int)v.size());
    rep(i, n) seg[n + i] = v[i];
    rep2(i, n) seg[i] = function(seg[2 * i], seg[2 * i + 1]);
  }

  void update(int x, T val) {
    x += n;
    seg[x] = val;
    while (x > 1) {
      x = x / 2;
      seg[x] = function(seg[2 * x], seg[2 * x + 1]);
    }
  }

  T get(int x) {
    x += n;
    return seg[x];
  }

  T get(int l, int r) {
    T left = identity;
    T right = identity;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2) left = function(left, seg[l++]);
      if (r % 2) right = function(seg[--r], right);
    }
    return function(left, right);
  }

  int getLevel(int index) {
    return floor(log2(index));
  }

  void display(bool showIndex = false) {
    // 最大の桁数
    int digit = 1;
    for (T x : seg) {
      digit = max(digit, (int)to_string(x).size());
    }

    // 表示用の値を作成
    int depth = getLevel(2 * n);
    vector<vs> rangeStrs(0), valStrs(0), indexStrs(0);
    rep(i, depth) {
      auto [start, end] = getIndexRangeOfLevel(i);
      vs subRangeStrs(0), subValStrs(0), subIndexStrs(0);
      rep3(j, start, end) {
        subRangeStrs.push_back(displayNodeRange(j));
        subValStrs.push_back(to_string(seg[j]));
        subIndexStrs.push_back("[" + to_string(j) + "]");
      }
      rangeStrs.push_back(subRangeStrs);
      valStrs.push_back(subValStrs);
      indexStrs.push_back(subIndexStrs);
    }

    // セルの幅を計算
    int cellWidth = 0;
    rep(i, depth) {
      int m = rangeStrs[i].size();
      rep(j, m) {
        cellWidth = max(cellWidth, (int)rangeStrs[i][j].size() * m / n);
        cellWidth = max(cellWidth, (int)valStrs[i][j].size() * m / n);
        if (showIndex) cellWidth = max(cellWidth, (int)indexStrs[i][j].size() * m / n);
      }
    }

    // 表示
    string sepate = displaySepate(cellWidth);
    int witdh = sepate.size();
    rep(i, depth) {
      cout << sepate << endl;
      if (showIndex) cout << displayNodes(witdh, indexStrs[i]) << endl;
      cout << displayNodes(witdh, rangeStrs[i]) << endl;
      cout << displayNodes(witdh, valStrs[i]) << endl;
    }
    cout << sepate << endl;
  }

private:
  pair<int, int> getIndexRangeOfLevel(int level) {
    int start = pow(2, level);
    int end = start * 2;
    return make_pair(start, end);
  }

  pair<int, int> getValRangeOfNode(int index) {
    int level = getLevel(index);
    int levelStart = pow(2, level);
    int indexInLevel = index - levelStart;
    int rangeSize = n / pow(2, level);
    int start = indexInLevel * rangeSize;
    int end = start + rangeSize;
    return make_pair(start, end);
  }

  string displaySepate(int cellWidth) {
    string res = "|";
    rep(i, n) {
      rep(j, cellWidth) res += "-";
      if (i != n - 1) res += "-";
    }
    res += "|";
    return res;
  }

  string displayNodes(int witdh, vector<string> nodes) {
    string res = "|";
    int cellWidth = (witdh - 1) / nodes.size() - 1;
    rep(i, nodes.size()) {
      res += displayCenter(cellWidth, nodes[i]);
      res += "|";
    }
    return res;
  }

  string displayNodeRange(int index) {
    if (index == 0) return ""; // 0番目のノードは存在しない
    auto [start, end] = getValRangeOfNode(index);
    if (start + 1 == end) return to_string(start);
    return "[" + to_string(start) + "," + to_string(end) + ")";
  }

  string displayCenter(int l, string s) {
    int space = l - s.size();
    int padRight = space / 2;
    int padLeft = space - padRight;
    string res = "";
    rep(i, padLeft) res += " ";
    res += s;
    rep(i, padRight) res += " ";
    return res;
  }
};
