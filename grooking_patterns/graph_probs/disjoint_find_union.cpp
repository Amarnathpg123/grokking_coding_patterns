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

vector<int> dsuf;

int find(int v) {
    if(dsuf[v] == -1) return v;
    return find(dsuf[v]);
}

void unionOp(int f, int t) {
    f = find(f);
    t = find(t);
    dsuf[f] = t;
}

bool isCyclic(vector<pair<int, int>> &edges) {
    for(auto &p: edges) {
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP) return 1;

        unionOp(fromP, toP);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int E, V; fastInput(E); fastInput(V);  //to find a cycle in a graph
    vector<pair<int, int>> edges;
    dsuf.resize(V, -1);
    for(int i = 0; i < E; ++i) {
        int from, to;
        fastInput(from); fastInput(to);
        edges.emplace_back(from, to);
    }

    isCyclic(edges) ? printf("Yes\n") : printf("No\n");
    return 0;
}

/*
4 4  
0 1
0 3
2 3
1 2
Yes
*/