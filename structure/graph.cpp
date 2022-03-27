#pragma once

/**
 * @brief グラフ
 * @docs docs/structure/graph.md
 */

using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int from, int to, T cost = 1) : from(from), to(to), cost(cost) {}
};

template <typename T>
struct Graph {
    vector<vector<Edge<T> > > edges;

    Graph() = default;
    Graph(int n) : edges(n) {}

    size_t size() { return edges.size(); }

    void add_edge(int from, int to, T cost = 1) {
        edges[from].emplace_back(from, to, cost);
        edges[to].emplace_back(to, from, cost);
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        edges[from].emplace_back(from, to, cost);
    }
};
