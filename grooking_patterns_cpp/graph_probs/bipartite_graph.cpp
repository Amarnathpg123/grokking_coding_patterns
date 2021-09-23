#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &color, int c, int node ) {
    if(color[node] != -1) return color[node] == c;

    color[node] = c;
    for(int i = 0; i < g[node].size(); ++i) {
        if(color[g[node][i]] != -1 and color[g[node][i]] != 1-c) return false;
        if(color[g[node][i]] == -1 and not dfs(g, color, 1-c, g[node][i])) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &g) { 
    vector<int> color(g.size(), -1);

    for(int i = 0; i < g.size(); ++i)
        if(color[i] == -1 and not dfs(g, color, 0, i)) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> graph = {{3}, {2, 4}, {1}, {0, 4}, {1, 3}};
    isBipartite(graph)? cout << "Yes\n" : cout << "No\n";

    return 0;
}