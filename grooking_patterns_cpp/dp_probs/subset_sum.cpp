#include <bits/stdc++.h>
using namespace std;

short SubsetSum(vector<long> &arr, vector<vector<short>> &dp, long const &sum, size_t i){
    if(i == 0) return dp[i][sum] = 0;

    if(sum == 0) return dp[i][sum] = 1;

    if(dp[i-1][sum] == -1) dp[i-1][sum] =  SubsetSum(arr, dp, sum, i-1);

    if(arr[i-1] > sum) return dp[i][sum] = dp[i-1][sum];
    else{
        if(dp[i-1][sum-arr[i-1]] == -1) dp[i-1][sum-arr[i-1]] = SubsetSum(arr, dp, sum-arr[i-1], i-1);
    }
        return dp[i][sum] = (dp[i-1][sum] | dp[i-1][sum-arr[i-1]]);
}

bool SubsetSumOpt(vector<long> &arr, long const &sum){
    if(arr.size() == 1) return arr[0] == sum;

    vector<bool> dp(sum+1, 0);
    dp[0] = 1;

    for(size_t i = 0; i < arr.size(); ++i)
        for(long s = sum; s > 0; --s)
            if(s >= arr[i])
                dp[s] = dp[s] or dp[s-arr[i]];

    return dp[sum];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<long> arr; long temp, sum;
    cin >> sum;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }

    vector<vector<short>> dp(arr.size()+1, vector<short> (sum+1, -1));
    if(SubsetSum(arr, dp, sum, arr.size())) printf("Subset found with sum: %ld\n", sum);
    else printf("Subset not found with sum: %ld\n", sum) ;

    if(SubsetSumOpt(arr, sum)) printf("Subset found with sum (Opt): %ld\n", sum);
    else printf("Subset not found with sum (Opt): %ld\n", sum) ;

    return 0;
}

//1 5 3 7 4, sum = 12 :: found