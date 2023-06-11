#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
/**
 * @brief 非可換セグメント木
 */

#include <bits/stdc++.h>

#include "../../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;

ll MOD = 998244353;

int main() {
  ll N, Q;
  cin >> N >> Q;

  SegmentTree<pii> seg(
      N,
      [](pii a, pii b) {
        return pii{(a.first * b.first) % MOD,
                   (a.second * b.first + b.second) % MOD};
      },
      pii(1, 0));

  vii ab(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    ab[i] = pii(a, b);
  }
  seg.build(ab);

  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 0) {
      ll p, c, d;
      cin >> p >> c >> d;
      seg.update(p, pii(c, d));
    } else {
      ll l, r, x;
      cin >> l >> r >> x;
      pii p = seg.get(l, r);
      cout << (p.first * x + p.second) % MOD << endl;
    }
  }
}
