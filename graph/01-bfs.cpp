/**
 * @brief BFS (幅優先探索)
 * @docs docs/graph/bfs.md
 */

#include "../structure/graph.cpp"

template <typename T>
struct ZeroOneBFS {
    vector<T> dist;
    vector<int> prev;

    ZeroOneBFS(Graph<T> g, int start) {
        // O(V+E)

        for (auto edge : g.edges)
            for (auto e : edge)
                if (e.cost != 0 && e.cost != 1)
                    throw runtime_error("Not 01-weighted graph");

        dist.resize(g.size(), -1);
        prev.resize(g.size(), -1);

        deque<int> q;  // 両端キュー
        q.push_font(start);
        dist[start] = 0;
        while (!q.empty()) {
            int from = q.front();
            q.pop_front();
            for (Edge<T> edge : g.edges[from]) {
                if (dist[edge.to] == -1) {
                    dist[edge.to] = dist[from] + edge.cost;
                    prev[edge.to] = from;

                    if (edge.cost == 0)
                        q.push_front(edge.to);
                    else
                        q.push_back(edge.to);
                }
            }
        }
    }

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
