#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;

void vist(int &node){
    printf("%d ", node);
}

void bfs_iter(graph const &G, vector<bool> &marked, int node){
    queue<int> qu;
    qu.push(node);
    while(qu.size()){
        node = qu.front(), qu.pop();
        if(not marked[node]){
            vist(node);
            marked[node] = true;
            for(int const &w: G[node])
                if(not marked[w]) qu.push(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    graph G;
    vector<bool> marked;
    G = {{1,3,2},{0,3},{0,3},{0,1,2,4},{3}};  //Adjacent list (neighbours list)

    printf("Graph: \n");
    for(size_t i = 0; i < G.size(); ++i){
        printf("node %ld: [",i);
        for(size_t j = 0; j < G[i].size(); ++j) printf(" %d ",G[i][j]);
        printf("]\n");
    }

    marked.assign(G.size(), false);
    printf("BFS (Iter): ");
    bfs_iter(G,marked,0);
    printf("\n");
    return 0;
}