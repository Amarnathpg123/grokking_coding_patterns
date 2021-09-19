#include <bits/stdc++.h>
using namespace std;

int selectMinVertex(vector<int> &value, vector<bool> &processed) {
    int vertex = 0;
    int minimum = INT_MAX;

    for(int i = 0; i < (int)value.size(); ++i) 
        if(not processed[i] and minimum > value[i]) {
            vertex = i;
            minimum = value[i];
        }
    return vertex;
}

void dijkstra(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> value(V, INT_MAX);
    vector<bool> processed(V, 0);

    value[0] = 0;

    for(int i = 0; i < V-1; ++i) {
        int U = selectMinVertex(value, processed);
        processed[U] = 1;

        for(int j = 0; j < V; ++j)
            if(graph[U][j] and not processed[j] and value[U] != INT_MAX and (value[U]+graph[U][j] < value[j])) {
                value[j] = value[U]+graph[U][j];
                parent[j] = U;
            }
    }

    printf("(Single Source) Shortest Path Graph (SPG): \n");
    for(int i = 0; i < V; ++i)
        if(parent[i] != -1) 
            printf("%d->%d  Edge Weight: %d\n", parent[i], i, graph[parent[i]][i]);

    printf("\nMinimum costs from source are: \n");
    for(int i = 0; i < V; ++i) printf("0->%d: cost: %d\n", i, value[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> graph = { {0,1,4,0,0,0},
                                  {1,0,4,2,7,0},
                                  {4,4,0,3,5,0},
                                  {0,2,3,0,4,6},
                                  {0,7,5,4,0,7},
                                  {0,0,0,6,7,0} };

    dijkstra(graph); // source is 0
    return 0;
}