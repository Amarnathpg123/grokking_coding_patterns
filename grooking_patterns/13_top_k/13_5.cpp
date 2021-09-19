#include <bits/stdc++.h>
using namespace std;

#define pls pair<long, size_t>
#define umls unordered_map<long, size_t>
#define umap_pq priority_queue<pls, vector<pls>, CompFreq>

class CompFreq{
public:
    constexpr inline bool operator()(pls const &a, pls const &b) const { return a.second > b.second; }
};

void find_top_k_frequent(umls &umap, size_t const &k, umap_pq &pq){
    for(auto &i: umap){
        pq.push(i);
        if(pq.size() > k) pq.pop();
    }
}

void print_pq(umap_pq &pq){
    while(pq.size()){
        printf("%ld ", pq.top().first); pq.pop();
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, k;
    cout << "Enter no. elements and k: " << endl; cin >> n; cin >> k;
    cout << "Enter the elements: " << endl;
    long temp;
    umls umap;
    while(n){
        cin >> temp; umap[temp]++;
        n--;
    }
    assert(umap.size() >= k);
    umap_pq pq;
    find_top_k_frequent(umap, k, pq);
    printf("Top %lu frequent elements are: ", k);
    print_pq(pq);
    return 0;
}