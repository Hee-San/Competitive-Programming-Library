#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
/**
 * @brief 区間の最小値
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree.hpp"
#include "../../../monoids/min.hpp"

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vi A(N);
  rep(i, N) cin >> A[i];

  segment_tree<min_monoid<int>> seg(A);

  rep(i, Q) {
    ll l, r;
    cin >> l >> r;
    cout << seg.range_get(l, r) << endl;
  }
}
