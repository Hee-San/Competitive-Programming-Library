#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
/**
 * @brief 区間の最小値
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
  ll N, Q;
  cin >> N >> Q;

  vi A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  SegmentTree<ll> seg(
      N, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);
  seg.build(A);

  for (ll i = 0; i < Q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << seg.get(l, r) << endl;
  }
}
