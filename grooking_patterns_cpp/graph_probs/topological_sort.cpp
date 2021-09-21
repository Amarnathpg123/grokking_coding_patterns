#include <bits/stdc++.h>
using namespace std;

bool detectCycleUtil(int i, unordered_map<int, vector<int>> &adj, vector<int> &visited) {
    if(visited[i] == 1) return true;
    if(visited[i] == 2) return false;
    
    visited[i] = 1;  //visited
    for(int j = 0; j < adj[i].size(); ++j) {
        if(detectCycleUtil(adj[i][j], adj, visited)) return true;
    }
    visited[i] = 2;  // processed
    return false;
}

bool detectCycle(int n, unordered_map<int, vector<int>> &adj) {
    vector<int> visited(n+1, 0);

    for(int i = 1; i <n+1; ++i) {
        if(!visited[i]) {
            if(detectCycleUtil(i, adj, visited)) return true;
        }
    }
    return false;
}

void dfs(int i, unordered_map<int, vector<int>> &adj, stack<int> &stk, vector<bool> &visited) {
    visited[i] = 1;
    for(int j = 0; j < adj[i].size(); ++j) 
        if(!visited[adj[i][j]]) dfs(adj[i][j], adj, stk, visited);
    
    stk.push(i);
}

void findTopoligicalOrder(int n, unordered_map<int, vector<int>> &adj, vector<int> &res) {
    if(detectCycle(n, adj)) return;  // topological sort can also be found on DAGs (no cycles)

    stack<int> stk;
    vector<bool> visited(n+1, 0);

    for(int i = 1; i < n+1; ++i) {
        if(!visited[i]) 
            dfs(i, adj, stk, visited);
    }

    while(!stk.empty()) {
        res.emplace_back(stk.top());
        stk.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<int, vector<int>> adj;
    adj[6].emplace_back(4);
    adj[6].emplace_back(5);

    adj[4].emplace_back(1);
    adj[4].emplace_back(5);

    adj[1].emplace_back(2);
    adj[2].emplace_back(3);
    adj[5].emplace_back(3);

    vector<int> res;
    findTopoligicalOrder(6, adj, res);

    for(auto &i: res) printf("%d ", i);
    printf("\n");
    return 0;
}   