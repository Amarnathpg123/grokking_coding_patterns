#include <bits/stdc++.h>
using namespace std;

size_t count_unique_bst_rec(unordered_map<size_t, size_t> &umap, size_t n){
    if(umap.find(n) != umap.end()) return umap[n];

    if(n <= 1) return 1;
    size_t res = 0;
    for(size_t i = 1; i <= n; ++i){
        size_t left = count_unique_bst_rec(umap, i-1);
        size_t right = count_unique_bst_rec(umap, n-i);
        res += left*right;
    }
    umap[n] = res;
    return res;
}

size_t binomial_coefficient(size_t n, size_t k){
    size_t res = 1;

    if(k > n-k) k = n-k;

    for(size_t i = 0; i < k; ++i){
        res *= n-i;
        res /= i+1;
    }
    return res;
}

size_t catalan_number(size_t const &n){
    return binomial_coefficient(2*n, n)/(n+1);   // C(n) = 2nCn/(n+1) or 2n!/((n+1)!n!)
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, ans = 0; cin >> n;
    unordered_map<size_t, size_t> umap;
    ans = count_unique_bst_rec(umap, n);
    printf("Total no. BSTs with 1 to %lu nodes (using recursion): %lu\n", n, ans);

    ans = catalan_number(n);
    printf("Total no. BSTs with 1 to %lu nodes (using binomial coefficients): %lu\n", n, ans);
    return 0;
}