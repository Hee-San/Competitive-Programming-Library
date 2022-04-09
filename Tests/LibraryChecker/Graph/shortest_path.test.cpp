#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
/**
 * @brief 重み付き、最短経路問題
 */

#include <bits/stdc++.h>

#include "../../../graph/dijkstra.cpp"
#include "../../../structure/graph.cpp"

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ll N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph<ll> g(N);
    for (ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.add_directed_edge(a, b, c);
    }

    Dijkstra<ll> dijkstra(g, s);
    ll dist = dijkstra.dist[t];
    vi path = dijkstra.path(t);

    cout << dist << ' ' << path.size() - 1 << endl;
    for (ll i = 0; i < path.size() - 1; i++) {
        cout << path[i] << ' ' << path[i + 1] << endl;
    }
}
