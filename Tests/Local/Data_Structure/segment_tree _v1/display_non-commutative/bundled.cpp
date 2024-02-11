#line 1 "Tests/Local/verifyer/../Data_Structure/segment_tree _v1/display_non-commutative/main.cpp"
#include <bits/stdc++.h>

#line 1 "structure/segment_tree/segment_tree_v1.cpp"
/**
 * @brief Segment Tree(セグメント木, 一点を更新・区間の演算結果を取得)
 * @docs docs/structure/segment_tree/segment_tree_v1.md
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
#line 7 "structure/segment_tree/segment_tree_v1.cpp"
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
};


template <typename T>
void display(SegmentTree<T> seg, function<string(T)> t2str, int pattern = 0) {
  // TODO: refactoring
  struct segNode {
    int index;
    T val;
    bool isLeaf = false;
    bool isUsed = true;
    pair<int, int> leaf_range = make_pair(-1, -1);
    vs strs;
    int width = 0;

    segNode(int index, T val) : index(index), val(val) {}
    void updateStrs(function<string(T)> t2str) {
      strs = { "[" + to_string(index) + "]", "", t2str(val) };
      if (isLeaf) { strs[1] = to_string(leaf_range.first); return; }
      if (!isUsed) { strs[1] = "/"; return; }
      strs[1] = "[" + to_string(leaf_range.first) + "," + to_string(leaf_range.second) + ")";
    }
  };

  struct util {
    static string displayCenter(int width, string str) {
      int space = width - str.size();
      int right = space / 2;
      int left = space - right;
      return string(left, ' ') + str + string(right, ' ');
    }
    static string separate(int width) {
      string s = "|";
      rep(i, width - 2) s += "-";
      return s + "|";
    }
    static string indent(int width) {
      return string(width, ' ');
    }
  };

  int n = seg.n;

  vector<segNode> nodes(n * 2, segNode(0, seg.identity));
  rep(i, n) {
    nodes[n + i] = segNode(n + i, seg.seg[n + i]);
    nodes[n + i].isLeaf = true;
    nodes[n + i].leaf_range = make_pair(i, i + 1);

    nodes[n + i].updateStrs(t2str);
  }
  int w = 0;
  rep(i, n) {
    w = max(w, (int)nodes[n + i].strs[0].size());
    w = max(w, (int)nodes[n + i].strs[1].size());
    w = max(w, (int)nodes[n + i].strs[2].size());
  }
  rep(i, n) {
    nodes[n + i].width = w;
  }

  rep2(i, n) {
    nodes[i] = segNode(i, seg.seg[i]);
    segNode left = nodes[i * 2];
    segNode right = nodes[i * 2 + 1];
    int left_end = left.leaf_range.second;
    int right_start = right.leaf_range.first;
    if (left_end == right_start) {
      nodes[i].leaf_range = make_pair(left.leaf_range.first, right.leaf_range.second);
    } else {
      nodes[i].isUsed = false;
    }
    nodes[i].updateStrs(t2str);
    nodes[i].width = left.width + right.width + 1;
  }

  vvi indexes;
  vi indents;
  if (pattern == 0) {
    int depth = ceil(log2(n * 2));
    indexes.resize(depth);
    indents.resize(depth);
    rep3(i, 1, n * 2) {
      int level = floor(log2(i));
      indexes[level].push_back(i);
    }
  } else if (pattern == 1) {
    vvi tmp_indexes(1);
    vi tmp_indents(1, 0);
    rep(i, n) {
      tmp_indexes[0].push_back(n + i);
    }
    while (true) {
      bool f = true;
      int last_size = tmp_indexes[tmp_indexes.size() - 1].size();
      tmp_indexes.push_back({});
      tmp_indents.push_back(tmp_indents[tmp_indents.size() - 1]);

      rep(i, last_size - 1) {
        segNode left = nodes[tmp_indexes[tmp_indexes.size() - 2][i]];
        segNode right = nodes[tmp_indexes[tmp_indexes.size() - 2][i + 1]];

        if (left.index / 2 == right.index / 2) {
          tmp_indexes[tmp_indexes.size() - 1].push_back(left.index / 2);
          f = false;
        } else {
          if (f) {
            tmp_indents[tmp_indents.size() - 1] += left.width + 1;
          }
        }
      }
      if (tmp_indexes[tmp_indexes.size() - 1].size() == 0) break;
    }
    rep2(i, tmp_indexes.size() - 1) {
      indexes.push_back(tmp_indexes[i]);
      indents.push_back(tmp_indents[i]);
    }
  }

  int last_width = 0;
  rep(i, indexes.size()) {
    int width = 1;
    for (int index : indexes[i]) {
      width += nodes[index].width + 1;
    }
    cout << util::indent(indents[i]) << util::separate(max(last_width, width)) << endl;
    cout << util::indent(indents[i]) << "|";
    rep(j, indexes[i].size()) {
      segNode node = nodes[indexes[i][j]];
      cout << util::displayCenter(node.width, node.strs[0]) << "|";
    }
    cout << endl;
    cout << util::indent(indents[i]) << "|";
    rep(j, indexes[i].size()) {
      segNode node = nodes[indexes[i][j]];
      cout << util::displayCenter(node.width, node.strs[1]) << "|";
    }
    cout << endl;
    cout << util::indent(indents[i]) << "|";
    rep(j, indexes[i].size()) {
      segNode node = nodes[indexes[i][j]];
      cout << util::displayCenter(node.width, node.strs[2]) << "|";
    }
    cout << endl;
    last_width = width;
  }
  cout << util::separate(last_width) << endl;
}
#line 4 "Tests/Local/verifyer/../Data_Structure/segment_tree _v1/display_non-commutative/main.cpp"

using namespace std;

int main() {
    int N;
    cin >> N;

    vs A(N);
    rep(i, N) cin >> A[i];

    SegmentTree<string> seg(N, [](string a, string b) { return a + b; }, "");
    seg.build(A);

    vs B = seg.seg;
    rep(i, B.size()) {
        cout << i << ": " << B[i] << endl;
    }
    cout << endl;

    function<string(string)> f = [](string a) { return a; };
    display(seg, f, 0);
    cout << endl;
    display(seg, f, 1);
}
