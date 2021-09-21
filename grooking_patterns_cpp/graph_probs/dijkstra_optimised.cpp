#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vumap vector<unordered_map<int,int>>

class Graph {
    int V = 0;
public:
    vumap adj;

    Graph(int v_) : V(v_) { adj.resize(V, {{}}); }
    void addEdge(int v, int w, int wt) {
        adj[v].emplace(make_pair(w, wt));  //undirected graph
        adj[w].emplace(make_pair(v, wt));
    }
    void dijkstra(int src);
};


void Graph::dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(not pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(const auto &i: adj[u]) {
            int v = i.first;
            int wt = i.second;

            if(dist[v] > dist[u]+wt) {
                dist[v] = dist[u]+wt;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    printf("(Single Source) Shortest Path Graph (SPG): \n");
    for(int i = 0; i < V; ++i)
        if(parent[i] != -1) 
            printf("%d->%d  Edge Weight: %d\n", parent[i], i, adj[parent[i]][i]);

    printf("\nMinimum costs from source are: \n");
    for(int i = 0; i < V; ++i) if(i != src) printf("%d->%d: cost: %d\n", src, i, dist[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);
    return 0;
}