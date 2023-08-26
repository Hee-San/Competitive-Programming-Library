#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
/**
 * @brief 非可換セグメント木
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

ll MOD = 998244353;

int main() {
  ll N, Q;
  cin >> N >> Q;

  SegmentTree<pl> seg(
    N,
    [](pl a, pl b) {
      return pl{ (a.first * b.first) % MOD,
                 (a.second * b.first + b.second) % MOD };
    },
    pl(1, 0));

  vpl ab(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    ab[i] = pl(a, b);
  }
  seg.build(ab);

  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 0) {
      ll p, c, d;
      cin >> p >> c >> d;
      seg.update(p, pl(c, d));
    } else {
      ll l, r, x;
      cin >> l >> r >> x;
      pl p = seg.get(l, r);
      cout << (p.first * x + p.second) % MOD << endl;
    }
  }
}
