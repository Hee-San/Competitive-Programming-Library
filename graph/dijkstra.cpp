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

        for (auto edge : g.edges)
            for (auto e : edge)
                if (e.cost < 0)
                    throw runtime_error("Not non-negative weights");

        dist.resize(g.size(), -1);
        prev.resize(g.size(), -1);

        priority_queue<int> q;  // 優先度付きキュー, ペアリングヒープ
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int from = q.top();
            q.pop();
            for (Edge<T> edge : g.edges[from]) {
                if (dist[edge.to] == -1) {
                    dist[edge.to] = dist[from] + edge.cost;
                    prev[edge.to] = from;
                    q.push(edge.to);
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
