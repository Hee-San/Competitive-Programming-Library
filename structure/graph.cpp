/**
 * @brief グラフ
 * @docs docs/structure/graph.md
 */

using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cosst;

    Edge(int from, int to, T cosst = 1) : from(from), to(to), cosst(cosst) {}
};

template <typename T>
struct Graph {
    vector<vector<Edge<T> > > edges;

    Graph() = default;
    Graph(int n) : edges(n) {}

    size_t size() { return edges.size(); }

    void add_edge(int from, int to, T cosst = 1) {
        edges[from].emplace_back(from, to, cosst);
        edges[to].emplace_back(to, from, cosst);
    }

    void add_directed_edge(int from, int to, T cosst = 1) {
        edges[from].emplace_back(from, to, cosst);
    }
};
