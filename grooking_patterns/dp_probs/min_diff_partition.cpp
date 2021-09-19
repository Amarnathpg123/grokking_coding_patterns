#include <bits/stdc++.h>
using namespace std;

size_t min_diff_dp(vector<unsigned> &arr) {
    size_t sum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(arr.size()+1, vector<bool> (sum+1, 0));

    for(size_t i = 0; i <= arr.size(); ++i) dp[i][0] = 1;
    for(size_t i = 1; i <= sum; ++i) dp[0][i] = 0;

    for(size_t i = 1; i <= arr.size(); ++i) {
        for(size_t j = 1; j <= sum; ++j){
            dp[i][j] = dp[i-1][j];

            if(arr[i-1] <= j)
                dp[i][j] = (dp[i-1][j] | dp[i-1][j-arr[i-1]]);
        }
    }

    size_t diff = 0;    

    for(long i = sum/2; i >= 0; --i) { 
        if(dp[arr.size()][i]) {
            diff = sum-2*i;
            break;
        }
    }
    return diff;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<unsigned> arr; unsigned temp;
    while(n) {
        cin >> temp; arr.push_back(temp);
        n--;
    }
    printf("Minimum difference parition of set is: %lu\n", min_diff_dp(arr));
    return 0;
}