#include <bits/stdc++.h>
using namespace std;

long lcs_rec(string &s, string &t, vector<vector<long>> &L, size_t i, size_t j){
    if(i == 0 or j == 0)
        return L[i][j] = 0;

    if(s[i-1] == t[j-1]){
        if(L[i-1][j-1] == -1) L[i-1][j-1] = lcs_rec(s, t, L, i-1, j-1);
        return 1+L[i-1][j-1];
    }
    else{
        if(L[i][j-1] == -1) L[i][j-1] = lcs_rec(s, t, L, i, j-1);
        if(L[i-1][j] == -1) L[i-1][j] = lcs_rec(s, t, L, i-1, j);
        return max(L[i][j-1], L[i-1][j]);
    }
}

void printLCS(string &s) {
    
    if(s.length() < 2) return;

    string t(s.rbegin(), s.rend());

    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s[i-1] == t[j-1] and i != j) dp[i][j] = 1+dp[i-1][j-1];
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
    cin.tie(0); cout.tie(0);

    string s, t;
    cout << "Enter the strings for lcs: " << endl; cin >> s;
    printLCS(s); // from one string to find longest palindrome
    // cin >> t;
    // vector<vector<long>> L(s.length()+1, vector<long> (t.length()+1, -1));
    // printf("Longest common subsequence length: %ld\n", lcs_rec(s, t, L, s.length(), t.length()));
    return 0;
}