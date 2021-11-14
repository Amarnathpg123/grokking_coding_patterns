//https://www.geeksforgeeks.org/maximum-cost-path-from-source-node-to-destination-node-via-at-most-k-intermediate-nodes/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void fastInput(T &x) {
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c = getchar(); }
    while(c < 48 or c > 57) c = getchar();
    if(neg) x *= -1;
}

int findShortestPath(
    int n, vector<vector<int> >& edges,
    int src, int dst, int K)
{
    vector<vector<pair<int, int> > > adjlist(
        n, vector<pair<int, int> >());
 
    queue<pair<int, int> > q;
 
    unordered_map<int, int> mp;
 
    int ans = INT_MIN;
 
    for (int i = 0; i < edges.size(); i++) {
 
        auto edge = edges[i];
 
        adjlist[edge[0]].push_back(
            make_pair(edge[1], edge[2]));
    }
 
    q.push({ src, 0 });
 
    int level = 0;
 
    while (!q.empty() && level < K + 2) {
 
        int sz = q.size();
 
        for (int i = 0; i < sz; i++) {
 
            auto pr = q.front();
 
            q.pop();
 
            if (pr.first == dst)
                ans = max(ans, pr.second);
 
            for (auto pr2 : adjlist[pr.first]) {
 
                if (mp.find(pr2.first) == mp.end() || mp[pr2.first] < pr.second+pr2.second) {
 
                    q.push({ pr2.first, pr.second+ pr2.second });
                    mp[pr2.first] = pr.second + pr2.second;
                }
            }
        }
 
        level++;
    }
 
    return ans != INT_MIN ? ans : -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int> > edges
        = { { 0, 1, 100 },
            { 1, 2, 100 },
            { 0, 2, 500 } };
 
    cout << findShortestPath(n, edges,
                             src, dst, k);
    return 0;
}