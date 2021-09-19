#include <bits/stdc++.h>
using namespace std;

#define u unsigned

class Graph {
    u V, connected_comps = 0;
    vector<vector<u>> adj;
    void DFSUtil(u &v, vector<bool> &visited);
public:
    Graph(u V_) : V(V_) { adj.assign(V, {}); }
    ~Graph(){}
    void addEdge(u v, u w);
    void connectedComponents();
};

void Graph::addEdge(u v, u w) {
    adj[v].emplace_back(w); adj[w].emplace_back(v);
}

void Graph::DFSUtil(u &v, vector<bool> &visited) {
    visited[v] = 1;
    cout << v << " ";

    for(auto &w: adj[v])
        if(not visited[w]) DFSUtil(w, visited);
}

void Graph::connectedComponents() {
    vector<bool> visited(V, 0);

    for(u v = 0; v < V; ++v)
        if(not visited[v]) {
            DFSUtil(v, visited);
            connected_comps++;
            cout << endl;
        }
    printf("Total number of connected components in the graph are: %u\n", connected_comps);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.connectedComponents();
    return 0;
}