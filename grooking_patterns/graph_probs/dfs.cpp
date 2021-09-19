#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V = 0;
public:
    vector<bool> visited;
    vector<vector<int>> adj;

    Graph(int v_) : V(v_) {
        visited.resize(V, 0);
        adj.resize(V, {});
    }
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    adj[v].emplace_back(w);  //undirected graph
    adj[w].emplace_back(v);
}

void Graph::DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for(int i = 0; i < (int)adj[v].size(); ++i)
        if(not visited[adj[v][i]]) DFS(adj[v][i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);

    g.DFS(0);
    return 0;
}