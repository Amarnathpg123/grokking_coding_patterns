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

class Node {
public:
    int parent = -1, rank = 0;
    Node() {}
};
class Edge {
public:
    int from, to, wt;
    Edge(int f, int t, int w) : from(f), to(t), wt(w) {}
};

vector<Node> dsuf;
vector<Edge*> mst;

int find(int v) {
    if(dsuf[v].parent == -1) return v;
    return dsuf[v].parent = find(dsuf[v].parent);
}

void unionOp(int f, int t) {
    f = find(f);
    t = find(t);

    if(dsuf[f].rank > dsuf[t].rank) dsuf[t].parent = f;
    else if(dsuf[f].rank < dsuf[t].rank) dsuf[f].parent = t;
    else {
        dsuf[t].parent = f;
        dsuf[f].rank++;
    }
}

void kruskals(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) -> bool { return a.wt<b.wt; }); //sort according to weights

    int i = 0, j = 0;
    while(i < (V-1) and j < (int)edges.size()) {   //number of edges in MST is V-1
        int fromP = find(edges[j].from);
        int toP = find(edges[j].to);

        if(fromP == toP) { ++j; continue; }

        unionOp(fromP, toP);
        mst.emplace_back(&edges[j]);
        ++i;
    }
}

void printMST() {
    printf("Minimum Spanning Tree (MST): \n");
    for(auto const &i: mst) 
        printf("%d->%d  Edge weight: %d\n", i->from, i->to, i->wt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int V, E; fastInput(V); fastInput(E);
    dsuf.resize(V, Node());

    vector<Edge> edges;
    for(int i = 0; i < E; ++i) {
        int f, t, w;
        fastInput(f); fastInput(t); fastInput(w);
        edges.emplace_back(Edge(f,t,w));
    }

    kruskals(edges, V);
    printMST();
    return 0;
}

/*
6 10
0 1 1
1 3 1
2 4 1
0 2 2
2 3 2
3 4 2
1 2 3 
1 4 3
4 5 3
3 5 4
*/  