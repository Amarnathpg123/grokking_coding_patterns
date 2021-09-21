#include <bits/stdc++.h>
using namespace std;

// #define max3(a,b,c) max(max(a,b),c)

// unsigned optimal_strategy_game(vector<unsigned> &arr){
//     vector<vector<unsigned>> dp(arr.size(), vector<unsigned> (arr.size(), 0));
    
//     size_t i, j, gap;
//     unsigned sum;

//     for(gap = 1; gap < arr.size(); ++gap){
//         for(i = 0, j = gap; gap < arr.size(); ++i, ++j){
//             if(i+1 == j) dp[i][j] = max(arr[i], arr[j]);
//             else{
//                 sum = accumulate(arr.begin()+i, arr.begin()+j+1, 0);
//                 dp[i][j] = max3(dp[i][j], sum-dp[i+1][j], sum-dp[i][j-1]);
//             }
//         }
//     }
//     return dp[0][arr.size()-1];
// }

long strategy_rec(vector<vector<long>> &dp, vector<long> &arr, long sum, size_t i, size_t j){
    if(i+1 == j) return dp[i][j] = max(arr[i], arr[j]);
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(sum-strategy_rec(dp, arr, sum-arr[i], i+1, j), 
                            sum-strategy_rec(dp, arr, sum-arr[j], i, j-1));
}

long optimal_strategy_game(vector<long> &arr){
    vector<vector<long>> dp(arr.size(), vector<long> (arr.size(), -1));
    long sum = accumulate(arr.begin(), arr.end(), 0);
    return strategy_rec(dp, arr, sum, 0, arr.size()-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<long> arr; long temp;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }

    printf("Maximum value from the strategy game is: %ld\n", optimal_strategy_game(arr));
    return 0;
}