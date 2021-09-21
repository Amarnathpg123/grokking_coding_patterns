#include <bits/stdc++.h>
using namespace std;

long edit_distance_dp(string &s, string &t, vector<vector<long>> &dp, size_t i, size_t j){
    if(i == 0) { dp[i][j] = j; return dp[i][j]; }

    if(j == 0) { dp[i][j] = i; return dp[i][j]; }

    if(s[i-1] == t[j-1]) {
        if(dp[i-1][j-1] == -1) dp[i-1][j-1] = edit_distance_dp(s, t, dp, i-1, j-1);
        dp[i][j] = dp[i-1][j-1];
        return dp[i][j];
    }

    else{
        if(dp[i][j-1] == -1) dp[i][j-1] = edit_distance_dp(s, t, dp, i, j-1);  // insert
        if(dp[i-1][j] == -1) dp[i-1][j] = edit_distance_dp(s, t, dp, i-1, j); // remove
        if(dp[i-1][j-1] == -1) dp[i-1][j-1] = edit_distance_dp(s, t, dp, i-1, j-1); // update

        dp[i][j] = 1+min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
    }
    return dp[i][j];
}

void edit_distance(string &s, string &t){
    vector<vector<size_t>> dp(2, vector<size_t> (s.length()+1, 0));

    for(size_t j = 0; j <= s.length(); ++j) dp[0][j] = j;  // remove

    for(size_t i = 1; i <= t.length(); ++i){
        short unsigned x = i%2, y = (i-1)%2;
        for(size_t j = 0; j <= s.length(); ++j){
            if(j == 0) dp[x][j] = i;
            else if(s[j-1] == t[i-1]) dp[x][j] = dp[y][j-1];
            else
                dp[x][j] = 1+min(min(dp[x][j-1], dp[y][j]), dp[y][j-1]);
        }
    }

    printf("Minimum number of operations are: %ld\n", dp[t.length()%2][s.length()]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    vector<vector<long>> dp(s.length()+1, vector<long> (t.length()+1, -1));
    printf("Minimum number of operations are: %ld\n", edit_distance_dp(s, t, dp, s.length(), t.length()));
    edit_distance(s, t);
    return 0;
}

//voldemort dumbledore  ---> 7