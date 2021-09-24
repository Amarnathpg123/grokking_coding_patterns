#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp(105, vector<int> (105, -1));

// int utility(int i, int j, string &A) {
//     if(dp[i][j] != -1) return dp[i][j];

//     if(i*j == 0) return dp[i][j] = 0;

//     if(i == j) return dp[i][j] = max(utility(i-1,j, A), utility(i,j-1,A));

//     else {
//         if(A[i-1] == A[j-1]) return dp[i][j] = 1+utility(i-1,j-1,A);
//         else return dp[i][j] = max(utility(i-1,j, A), utility(i,j-1,A));
//     }

void printLRS(string &s) {
    if(s.length() < 2) return;

    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s[i-1] == s[j-1] and i != j) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = n;
    vector<int> left, right;
    string res;
    while(i > 0 and j > 0) {
        if(dp[i][j] == 1+dp[i-1][j-1]) {
            res += s[i-1];   //only i is giving currect string not j
            left.push_back(i);
            i--; j--;
        }
        else if(dp[i][j] == dp[i-1][j]) i--;
        else j--;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    printLRS(s);
    return 0;
}