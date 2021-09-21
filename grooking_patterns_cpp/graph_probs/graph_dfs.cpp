//just dfs (pre order and post order dfs)

//recusrsive method

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;

void visit(int &node){
    printf("%d ", node);
}

void pre_dfs_rec(graph const &G, vector<bool> &marked, int node){
    visit(node);
    marked[node] = true;
    for(int const &w: G[node])
        if(not marked[w]) pre_dfs_rec(G, marked, w);
}

void post_dfs_rec(graph const &G, vector<bool> &marked, int node){
    marked[node] = true;
    for(int const &w: G[node])
        if(not marked[w]) post_dfs_rec(G, marked, w);
    visit(node);
}

void dfs_iter(graph const &G, vector<bool> &marked, int node){
    stack<int> sk;
    sk.push(node);
    while(sk.size()){
        node = sk.top(); sk.pop();
        if (not marked[node]){
            visit(node);
            marked[node] = true;
            for(int const &w: G[node])
                if(not marked[w]) sk.push(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    graph G;
    vector<bool> marked;
    G = {{1,2,3},{0,3},{0,3},{0,1,2,4},{3}};  //Adjacent list (neighbours list)

    printf("Graph: \n");
    for(size_t i = 0; i < G.size(); ++i){
        printf("node %llu: [",i);
        for(size_t j = 0; j < G[i].size(); ++j) printf(" %d ",G[i][j]);
        printf("]\n");
    }

    marked.assign(G.size(), false);
    printf("Pre_Order_DFS (Rec): ");
    pre_dfs_rec(G,marked,0);
    printf("\n");

    marked.assign(G.size(), false);
    printf("Post_Order_DFS (Rec): ");
    post_dfs_rec(G,marked,0);
    printf("\n");

    marked.assign(G.size(), false);
    printf("DFS (Iter): ");
    dfs_iter(G,marked,0);
    printf("\n");
    return 0;
}