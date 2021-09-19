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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s, t;
    cout << "Enter the strings for lcs: " << endl; cin >> s >> t;
    vector<vector<long>> L(s.length()+1, vector<long> (t.length()+1, -1));
    printf("Longest common subsequence length: %ld\n", lcs_rec(s, t, L, s.length(), t.length()));
    return 0;
}