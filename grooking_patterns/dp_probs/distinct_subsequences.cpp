#include <bits/stdc++.h>
using namespace std;

int utility(int i, int j, string &A, string &B, vector<vector<int>> &dp) {
    if(dp[i][j] != -1) return dp[i][j];

    if(j == 0) return dp[i][j] = 1;
    if(i == 0) return dp[i][j] = 0;

    int count = 0;
    if(A[i-1] == B[j-1]) count += utility(i-1,j-1,A,B,dp);

    count += utility(i-1, j, A, B, dp);
    return dp[i][j] = count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string A, B;
    cin >> A >> B;
    vector<vector<int>> dp(A.size()+1, vector<int> (B.size()+1, -1));
    printf("Count no. of distinct subsequences of B in A: %d\n", utility(A.size(), B.size(), A, B, dp));

    return 0;
}