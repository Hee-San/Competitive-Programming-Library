#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
/**
 * @brief 区間の和・一点加算 Range Sum Query (RSQ)
 */

#include <bits/stdc++.h>

#include "../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll n, q;
    cin >> n >> q;
    SegmentTree<ll> seg(
        n, [](ll a, ll b) { return a + b; }, 0);
    seg.build(vi(n, 0));

    for (ll i = 0; i < q; i++) {
        ll com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            x--;
            seg.update(x, seg.get(x) + y);
        } else {
            x--;
            y--;
            cout << seg.get(x, y + 1) << endl;
        }
    }
}
