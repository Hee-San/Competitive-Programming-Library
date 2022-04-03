/**
 * @brief 01-BFS
 * @docs docs/graph/01-bfs.md
 */

#include "../structure/graph.cpp"

template <typename T>
struct ZeroOneBFS {
    vector<T> dist;
    vector<int> prev;

    ZeroOneBFS(Graph<T> g, vector<int> starts) {
        // O(V+E)

        for (auto edge : g.edges)
            for (auto e : edge)
                if (e.cost != 0 && e.cost != 1)
                    throw runtime_error("Not 01-weighted graph");

        dist.resize(g.size(), -1);
        prev.resize(g.size(), -1);

        deque<int> q;  // 両端キュー
        for (int start : starts) {
            q.push_back(start);
            dist[start] = 0;
        }
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

    ZeroOneBFS(Graph<T> g, int start) {
        vector<int> starts = {start};
        ZeroOneBFS(g, starts);
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
