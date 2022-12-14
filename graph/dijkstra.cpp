/**
 * @brief ダイクストラ法
 * @docs docs/graph/dijkstra.md
 */

#include "../structure/graph.cpp"

template <typename T>
struct Dijkstra {
    vector<T> dist;
    vector<int> prev;

    Dijkstra(Graph<T> g, int start) {
        // O(E+VlogV)

        validateNonNegativeWeights(g);

        dist.resize(g.size(), -1);
        prev.resize(g.size(), -1);

        // 優先度付きキュー, ペアリングヒープ
        priority_queue<pair<T, int> > q;

        q.push({0, start});
        dist[start] = 0;

        while (!q.empty()) {
            T cost = q.top().first;
            int from = q.top().second;
            q.pop();

            // 既に探索済みなら飛ばす
            if (dist[from] < cost) continue;

            for (Edge<T> edge : g.edges[from]) {
                if (dist[edge.to] == -1) {
                    dist[edge.to] = cost + edge.cost;
                    prev[edge.to] = from;
                    q.push({dist[edge.to], edge.to});
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

    void validateNonNegativeWeights(Graph<T> g) {
        for (auto edge : g.edges)
            for (auto e : edge)
                if (e.cost < 0)
                    throw runtime_error("Not non-negative weights");
    }
};
