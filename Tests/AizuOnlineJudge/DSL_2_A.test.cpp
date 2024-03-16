#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
/**
 * @brief 区間の最小値・一点更新 Range Minimum Query (RMQ)
 */

#include <bits/stdc++.h>

#include "../../common/common.cpp"
#include "../../structure/segment_tree/segment_tree.hpp"
#include "../../monoids/min.hpp"

using namespace std;

int main() {
  ll n, q;
  cin >> n >> q;
  ll init = (1LL << 31) - 1;
  vl a(n, init);
  segment_tree<min_monoid<ll>> seg(a);

  for (ll i = 0; i < q; i++) {
    ll com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.point_set(x, y);
    } else {
      cout << seg.range_get(x, y + 1) << endl;
    }
  }
}
