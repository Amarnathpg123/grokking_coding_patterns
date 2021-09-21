//to find single source shortest path (same as dijkstra but bellman ford can detect negative edge weight cycles)
//for undirected graph, there will be negative edge cycle if we have atleast one negative edge and both will fail (infinte loop)
// for directed graph if we have negative edge weight cycle then dijkstra gives wrong answer but bellman won't give any answer
// for directed graph: negative edge weight cycle is a cycle with sum of all edge weight gives negative
//if there is an edge with negative edge weight and grapg doesn't have negative edge weight cycle then both give correct answer
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void fastInput(T &x) {
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c = getchar(); }
    while(c < 48 or c > 57) c = getchar();
    for(; (c > 47 and c < 58); c = getchar()) x = (x<<1) + (x<<3) + (c&15); //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

int V, E; 

class Edge {
public:
    int from, to, wt;
    Edge() {}
    Edge(int f, int t, int w) : from(f), to(t), wt(w) {}
};

void bellmanFord(vector<Edge> &edges, int src) {
    vector<int> parent(V, -1);
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    bool updated = 0;
    for(int i = 0; i < (V-1); ++i) {
        updated = 0;

        for(int j = 0; j < E; ++j) {
            int u = edges[j].from;
            int v = edges[j].to;
            int wt = edges[j].wt;

            if(dist[u] != INT_MAX and dist[u]+wt<dist[v]) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                updated = 1;
            }
        }
        if(not updated) break;
    }

    //to check negative edge cycle
    for(int j = 0; j < E; ++j) {
        int u = edges[j].from;
        int v = edges[j].to;
        int wt = edges[j].wt;

        if(dist[u] != INT_MAX and dist[u]+wt<dist[v]) {
            printf("Graph has Negative Edge Cycle (so algorithm won't work)\n"); return;
        }
    }

    printf("(Single Source) Shortest Path Graph (SPG): \n");
    for(int i = 0; i < V; ++i)
        if(parent[i] != -1) 
            printf("%d->%d \n", parent[i], i);

    printf("\nMinimum costs from source are: \n");
    for(int i = 0; i < V; ++i) if(i != src) printf("%d->%d: cost: %d\n", src, i, dist[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    fastInput(V); fastInput(E);
    vector<Edge> edges(E, Edge());

    for(int i = 0; i < E; ++i) {
        fastInput(edges[i].from);
        fastInput(edges[i].to);
        fastInput(edges[i].wt);
    }

    bellmanFord(edges, 0);
    return 0;
}

/*
5 10
0 1 6
0 2 7
1 2 8
1 3 -4
1 4 5
2 3 9
2 4 -3
3 4 7
3 0 2
4 1 -2
*/