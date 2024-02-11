#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
/**
 * @brief 区間の最小値
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree_v1.cpp"

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vi A(N);
  rep(i, N) cin >> A[i];

  SegmentTree<int> seg(
    N, [](int a, int b) { return min(a, b); }, INT_MAX);
  seg.build(A);

  rep(i, Q) {
    ll l, r;
    cin >> l >> r;
    cout << seg.get(l, r) << endl;
  }
}
