#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
/**
 * @brief 区間の最小値・一点更新 Range Minimum Query (RMQ)
 */

#include <bits/stdc++.h>

#include "../../structure/segment_tree/segment_tree_v1.cpp"

using namespace std;

int main() {
  ll n, q;
  cin >> n >> q;
  SegmentTree<ll> seg(
    n, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);
  seg.build(vl(n, (1LL << 31) - 1));

  for (ll i = 0; i < q; i++) {
    ll com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.update(x, y);
    } else {
      cout << seg.get(x, y + 1) << endl;
    }
  }
}
