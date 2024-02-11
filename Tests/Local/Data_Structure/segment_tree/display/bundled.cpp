#line 1 "Tests/Local/verifyer/../Data_Structure/segment_tree/display/main.cpp"
#include <bits/stdc++.h>

#line 1 "structure/segment_tree/segment_tree.cpp"
/**
 * @brief Segment Tree(セグメント木, 一点を更新・区間の演算結果を取得)
 * @docs docs/structure/segment_tree/segment_tree.md
 */

#line 1 "common/common.cpp"
/**
 * @brief 共通設定
 * @docs docs/common/common.md
 */

#line 7 "common/common.cpp"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); i++)
#line 7 "structure/segment_tree/segment_tree.cpp"
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

  void display() {
    // 最大の桁数
    int digit = 1;
    for (T x : seg) {
      digit = max(digit, (int)to_string(x).size());
    }

    // 深さごと
    int depth = log2(n) + 1;
    vector<vs> displayValues(depth * 2);
    rep(i, depth) {
      int rangeSize = n / pow(2, i);
      rep(j, pow(2, i)) {
        int index = pow(2, i) + j;
        displayValues[i * 2].push_back(displayNodeRange(index));
      }
      rep(j, pow(2, i)) {
        int index = pow(2, i) + j;
        displayValues[i * 2 + 1].push_back(to_string(seg[index]));
      }
    }

    int cellWidth = 0;
    rep(i, depth) {
      rep(j, displayValues[i].size()) {
        cellWidth = max(cellWidth, (int)displayValues[i][j].size());
      }
    }

    // 表示
    string sepate = displaySepate(cellWidth);
    int witdh = sepate.size();
    rep(i, depth) {
      cout << sepate << endl;
      cout << displayNodes(witdh, displayValues[i * 2]) << endl;
      cout << displayNodes(witdh, displayValues[i * 2 + 1]) << endl;
    }
    cout << sepate << endl;
  }

private:
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
    int leafStartIndex = seg.size() / 2; // 葉ノードの開始インデックスをより明確に表現
    if (index >= leafStartIndex) {
      // 葉のノードの場合
      int leafIndex = index - leafStartIndex;
      return to_string(leafIndex); // 範囲表示ではなくインデックスのみ
    } else {
      // 内部ノードの場合の範囲計算
      int level = floor(log2(index));
      int levelStart = pow(2, level);
      int indexInLevel = index - levelStart;
      int rangeSize = n / pow(2, level);
      int start = indexInLevel * rangeSize;
      int end = start + rangeSize;
      return "[" + to_string(start) + "," + to_string(end) + ")";
    }
  }

  string displayCenter(int l, string s) {
    int space = l - s.size();
    int padLeft = space / 2;
    int padRight = space - padLeft;
    string res = "";
    rep(i, padLeft) res += " ";
    res += s;
    rep(i, padRight) res += " ";
    return res;
  }
};
#line 4 "Tests/Local/verifyer/../Data_Structure/segment_tree/display/main.cpp"

using namespace std;

int main() {
    int N;
    cin >> N;

    vi A(N);
    rep(i, N) cin >> A[i];

    SegmentTree<int> seg(N, [](int a, int b) { return a + b; }, 0);
    seg.build(A);

    seg.display();
}
