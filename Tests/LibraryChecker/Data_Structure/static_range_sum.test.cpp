#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
/**
 * @brief 区間和
 */

#include <bits/stdc++.h>


#include "../../../structure/segment_tree/segment_tree.hpp"
#include "../../../monoids/plus.hpp"

using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;

  vl A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];

  segment_tree<plus_monoid<ll>> seg(A);

  for (ll i = 0; i < Q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << seg.range_get(l, r) << endl;
  }
}
