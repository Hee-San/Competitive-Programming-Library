#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
/**
 * @brief 区間和、累積和を使ったテスト
 */

#include <bits/stdc++.h>

#include "../../../structure/cumulative_sum.cpp"

using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;

  vl A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  CumulativeSum<ll> sumA(A);

  for (ll i = 0; i < Q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << sumA.get(l, r) << endl;
  }
}
