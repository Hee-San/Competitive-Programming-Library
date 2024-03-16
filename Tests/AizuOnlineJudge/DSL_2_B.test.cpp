#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
/**
 * @brief 区間の和・一点加算 Range Sum Query (RSQ)
 */

#include <bits/stdc++.h>

#include "../../structure/segment_tree/segment_tree.hpp"
#include "../../monoids/plus.hpp"


using namespace std;

int main() {
  ll n, q;
  cin >> n >> q;
  segment_tree<plus_monoid<ll>> seg(n);

  for (ll i = 0; i < q; i++) {
    ll com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      x--;
      seg.point_set(x, seg.point_get(x) + y);
    } else {
      x--;
      y--;
      cout << seg.range_get(x, y + 1) << endl;
    }
  }
}
