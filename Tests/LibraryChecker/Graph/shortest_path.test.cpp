#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
/**
 * @brief 重み付き、最短経路問題
 */

#include <bits/stdc++.h>

#include "../../../graph/dijkstra.cpp"
#include "../../../structure/graph.cpp"

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M, s, t;
  cin >> N >> M >> s >> t;

  Graph<ll> g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    g.add_directed_edge(a, b, c);
  }

  Dijkstra<ll> dijkstra(g, s);
  ll dist = dijkstra.dist[t];

  if (dist == -1) {
    cout << -1 << endl;
    return 0;
  }

  vi path = dijkstra.path(t);
  cout << dist << ' ' << path.size() - 1 << endl;
  for (int i = 0; i < path.size() - 1; i++) {
    cout << path[i] << ' ' << path[i + 1] << endl;
  }
}
