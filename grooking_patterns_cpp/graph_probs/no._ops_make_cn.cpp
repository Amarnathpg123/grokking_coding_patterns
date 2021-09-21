#include <bits/stdc++.h>
using namespace std;

#define u unsigned
#define puu pair<u,u>
#define vpuu vector<puu>

void DFS(unordered_map<u, vector<u>> &adj, u curr, vector<bool> &visited){
    visited[curr] = true;
    for(u &i: adj[curr])
        if(not visited[i]) DFS(adj, i, visited);
}

int makeConnected(u &n, vpuu &conns){
    vector<bool> visited(n, 0);
    unordered_map<u, vector<u>> adj;

    u edges = conns.size();
    for(puu &t: conns) adj[t.first].push_back(t.second), adj[t.second].push_back(t.first);

    if(edges < n-1) return -1;

    u components = 0;
    for(u i = 0; i < n; ++i)
        if(not visited[i]){
            components++;
            DFS(adj, i, visited);
        }

    u reduntant_edges_min_spanning = edges - ((n-1) - (components-1));
    if(reduntant_edges_min_spanning >= (components-1)) return (components-1);
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    u n, t; cin >> n >> t;
    vpuu conns;
    puu temp;
    while(t){
        cin >> temp.first >> temp.second;
        conns.push_back(temp);
        t--;
    }

    printf("Minimum no. ops to make the network connected: %d\n", makeConnected(n, conns));
    return 0;
}