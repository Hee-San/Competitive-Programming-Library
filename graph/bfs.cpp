/**
 * @brief BFS (幅優先探索)
 * @docs docs/graph/bfs.md
 */

#include "../structure/graph.cpp"

template <typename T>
struct BFS {
  vector<T> dist;
  vector<int> prev;

  BFS(Graph<T> g, vector<int> starts) {
    // O(V+E)

    for (auto edge : g.edges)
      for (auto e : edge)
        if (e.cost != 1) throw runtime_error("Not un-weighted graph");

    dist.resize(g.size(), -1);
    prev.resize(g.size(), -1);

    queue<int> q;  // FIFO
    for (int start : starts) {
      q.push(start);
      dist[start] = 0;
    }
    while (!q.empty()) {
      int from = q.front();
      q.pop();
      for (Edge<T> edge : g.edges[from]) {
        if (dist[edge.to] == -1) {
          dist[edge.to] = dist[from] + 1;
          prev[edge.to] = from;
          q.push(edge.to);
        }
      }
    }
  }

  BFS(Graph<T> g, int start) : BFS<T>(g, vector<int>({ start })) {}

  vector<int> path(int to) {
    vector<int> path;
    while (to != -1) {
      path.push_back(to);
      to = prev[to];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};
