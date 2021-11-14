//https://codeforces.com/problemset/problem/602/C
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

int max_dist = 0;
vector<bool> visited;
void BFS(vector<vector<bool>> &g) {
    queue<int> q;
    q.push(0);

    int dist = 0;
    bool f = 0;
    while(q.size()) {
        int x = q.size();
        dist++;
        while(x--) {
            int t = q.front(); q.pop();
            if(not visited[t]) {
                visited[t] = 1;
                for(int i = 0; i < g[t].size(); ++i) {
                    if(g[t][i]) {
                        if(i == g.size()-1) {f = 1; break;}
                        if(not visited[i]) q.push(i);
                    }
                }
                if(f) break;
            }
        }
        if(f) break;
    }
    if(f) max_dist = max(max_dist, dist);
    else max_dist = INT_MAX;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; fastInput(n); fastInput(m);
    vector<vector<bool>> rail(n, vector<bool> (n,0)), road(n, vector<bool> (n,0));

    int t1,t2;
    while(m--) {
        fastInput(t1), fastInput(t2);
        rail[t1-1][t2-1] = 1; rail[t2-1][t1-1] = 1;
    }

    for(int i = 0;i < rail.size(); ++i) {
        for(int j = 0; j < rail[0].size(); ++j) {
            if(not rail[i][j] and i != j) road[i][j] = 1;
        }
    }

    visited.resize(n, 0);
    BFS(rail);
    fill(visited.begin(), visited.end(), 0);
    BFS(road);

    if(max_dist == INT_MAX) cout << "Not possible" << endl;
    else cout << "Maximum time to reach both by rail and road: " << max_dist << endl;
    return 0;
}