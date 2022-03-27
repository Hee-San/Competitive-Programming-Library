#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C"
/**
 * @brief 幅優先探索
 */

#include <bits/stdc++.h>

#include "../../graph/bfs.cpp"
#include "../../structure/graph.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll n;
    cin >> n;

    Graph<ll> g(n);
    for (ll i = 0; i < n; i++) {
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll v;
            cin >> v;
            g.add_edge(i, --v);
        }
    }

    BFS<ll> bfs(g, 0);

    for (ll i = 0; i < n; i++) {
        cout << i + 1 << " " << bfs.dist[i] << " " << bfs.prev[i] << endl;
    }
}
