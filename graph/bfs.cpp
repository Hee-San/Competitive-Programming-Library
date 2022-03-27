/**
 * @brief BFS (幅優先探索)
 * @docs docs/graph/bfs.md
 */

#include "../structure/graph.cpp"

template <typename T>
struct BFS {
    vector<T> dist;
    vector<int> prev;

    BFS(Graph<T> g, int start) {
        // 重みなしグラフかチェック
        for (auto& e : g.edges) {
            if (e.size() != 1) {
                throw runtime_error("Not unweighted graph");
            }
        }

        dist.resize(g.size(), -1);
        prev.resize(g.size(), -1);

        queue<int> q;
        q.push(start);
        dist[start] = 0;
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
