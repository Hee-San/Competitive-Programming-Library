#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
/**
 * @brief Range Minimum Query (RMQ)
 */

#include <bits/stdc++.h>

#include "../../structure/segment_tree/segment_tree.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll n, q;
    cin >> n >> q;
    auto seg = SegmentTree<ll>(
        vi(n, 1 << 31 - 1), [](ll a, ll b) { return min(a, b); }, LLONG_MAX);

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