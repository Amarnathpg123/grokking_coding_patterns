#include <bits/stdc++.h>
using namespace std;

int utility(int i, int j, int year, vector<int> &wines, vector<vector<int>> &dp) {
    if(dp[i][j] != -1) return dp[i][j];

    if(i == j) return dp[i][j] = wines[i]*year;
    else if(i < j) {
        int left = utility(i+1,j,year+1,wines, dp) + wines[i]*year;
        int right = utility(i,j-1,year+1,wines,dp) + wines[j]*year;

        return dp[i][j] = max(left, right);
    }
    else return dp[i][j] = 0;
}

int findMaxProfit(vector<int> &wines) {
    vector<vector<int>> dp(wines.size(), vector<int> (wines.size(), -1));
    return utility(0,wines.size()-1,1,wines,dp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> wines = {2,4,6,2,5};
    printf("Maximm profit that can be earned: %d\n", findMaxProfit(wines));
    return 0;
}