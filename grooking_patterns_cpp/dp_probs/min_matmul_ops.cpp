#include <bits/stdc++.h>
using namespace std;

size_t min_matmul_ops(vector<unsigned> &arr){
    vector<vector<size_t>> dp(arr.size(), vector<size_t> (arr.size(), 0));

    size_t i, j, gap, temp;
    
    for(gap = 2; gap < arr.size(); ++gap){
        for(i = 1, j = gap; j < arr.size(); ++i, ++j){
            dp[i][j] = INT64_MAX;
            for(size_t k = i; k < j; ++k){
                temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(temp < dp[i][j]) dp[i][j] = temp;
            }
        }
    }

    return dp[1][arr.size()-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<unsigned> arr; unsigned temp;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }

    printf("Minimum matrix multiplications operations are: %llu\n", min_matmul_ops(arr));
    return 0;
}