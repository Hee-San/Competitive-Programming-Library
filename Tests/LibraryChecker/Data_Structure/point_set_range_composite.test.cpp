#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
/**
 * @brief 非可換セグメント木
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree.hpp"
#include "../../../monoids/monoid.hpp"

using namespace std;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

ll MOD = 998244353;

struct linear_function_monoid : public Monoid<pl> {
  pl unit() override { return pl(1, 0); }
  pl mult(const pl& a, const pl& b) override {
    // a(cx + d) + b = acx + ad + b
    return pl{ (a.first * b.first) % MOD,
               (a.second * b.first + b.second) % MOD };
  }
};


int main() {
  ll N, Q;
  cin >> N >> Q;

  vpl ab(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    ab[i] = pl(a, b);
  }
  segment_tree<linear_function_monoid> seg(ab);

  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 0) {
      ll p, c, d;
      cin >> p >> c >> d;
      seg.point_set(p, pl(c, d));
    } else {
      ll l, r, x;
      cin >> l >> r >> x;
      pl p = seg.range_get(l, r);
      cout << (p.first * x + p.second) % MOD << endl;
    }
  }
}
