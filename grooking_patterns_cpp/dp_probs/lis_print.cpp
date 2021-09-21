#include <bits/stdc++.h>
using namespace std;

unsigned lis(vector<unsigned> &A){
    vector<unsigned> L;
    vector<unsigned> increasing_order = {};
    vector<int> prev;
    L.assign(A.size(), 1);
    prev.assign(A.size(), -1);
    for(size_t i = 1; i < L.size(); ++i) {
        unsigned temp = 0;
        for(size_t k = 0; k < i; ++k) {
            if(A[k] < A[i])
                if(L[k] > temp) temp = L[k], prev[i] = k;
        }
        if(temp) L[i] = 1 + temp;
    }
    auto maxe = max_element(L.begin(), L.end());
    if(maxe != L.end()) {
        size_t d = distance(L.begin(), maxe);
        while(1) {
            increasing_order.push_back(A[d]);
            if(prev[d] == -1) break;
            d = prev[d];
        }
        printf("logest increasing subseq: ");
        while(increasing_order.size()) printf("%u ", increasing_order[increasing_order.size()-1]), increasing_order.pop_back();
        printf("\n");
        return *maxe;
    }
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    srand(808);
    vector<unsigned> A;
    unsigned r, n = 100;
    while(n--) r = rand(), A.push_back(r), printf("%u ", r);
    printf("\n");
    cout << lis(A);
    return 0;
}