#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(105, vector<int> (105, -1));

class Solution {
    string A;

int utility(int i, int j, string &A) {
    if(dp[i][j] != -1) return dp[i][j];

    if(i*j == 0) return dp[i][j] = 0;

    if(i == j) return dp[i][j] = max(utility(i-1,j, A), utility(i,j-1,A));

    else {
        if(A[i-1] == A[j-1]) return dp[i][j] = 1+utility(i-1,j-1,A);
        else return dp[i][j] = max(utility(i-1,j, A), utility(i,j-1,A));
    }
}
    public:
        Solution() {
            cin >> A;
        }
        int solve();
};



int Solution::solve() {
    if(utility(A.size(), A.size(), A) > 1) return 1;
    else return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    Solution sol;
    cout << sol.solve();
    return 0;
}