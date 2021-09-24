#include <bits/stdc++.h>
using namespace std;

bool utility(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    if(dp[i][j] != -1) return dp[i][j];

    if(i < 0 or j < 0) return 0;

    if(i == 0 and j == 0) return dp[i][j] = 1;

    if(i == 0) {
        if(t[j-1] == '*') return dp[i][j] = utility(i,j-2,s,t,dp);
        else return dp[i][j] = 0;
    }

    if(j == 0) return dp[i][j] = 0;

    if(s[i-1] == t[j-1] or t[j-1] == '.')
        return dp[i][j] = utility(i-1,j-1,s,t,dp);

    else if(t[j-1] == '*') {
        if(s[i-1] == t[j-2] or t[j-2] == '.') 
            return dp[i][j] = utility(i-1,j,s,t,dp) or utility(i,j-2,s,t,dp);
        else return dp[i][j] = utility(i,j-2,s,t,dp);
    }

    return dp[i][j] = 0;
}

bool isRegex(string &s, string &t) {
    if(s.compare(t) == 0) return 1;
    vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));

    return utility(s.length(),t.length(),s,t,dp);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string s, t;
    cin >> s >> t;  ///check t is the regex of s
    if(isRegex(s, t)) cout << "Yes\n";
    else cout << "NO\n";
    return 0;
}