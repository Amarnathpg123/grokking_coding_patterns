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

long lcs_palindrome(string &s){
    vector<vector<long>> L(s.length()+1, vector<long> (s.length()+1, -1));
    string t(s.rbegin(), s.rend());
    return lcs_rec(s, t, L, s.length(), s.length());
}

size_t min_insertions(string &s){
    vector<vector<size_t>> dp(s.length(), vector<size_t>(s.length(),0));

    for(size_t gap = 1; gap < s.length(); ++gap){       
        for(size_t l = 0, h = gap; h < s.length(); ++l, ++h)
            dp[l][h] = (s[l] == s[h])
                        ? dp[l-1][h+1]
                        : min(dp[l][h-1], dp[l+1][h])+1
                        ;
    }

    return dp[0][s.length()-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    printf("Minimum nunber of insertions needed to convert into a palindrome is (lcs method): %lld\n", (s.length()-lcs_palindrome(s)));

    printf("Minimum nunber of insertions needed to convert into a palindrome is: %llu\n", min_insertions(s));
    return 0;
}