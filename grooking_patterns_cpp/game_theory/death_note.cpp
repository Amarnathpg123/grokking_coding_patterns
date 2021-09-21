//https://practice.geeksforgeeks.org/problems/who-will-receive-the-death-note/0/
// #Game_Theory #Sprunge_Grundy_Theorem
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void fastInput(T &x) {
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c = getchar(); }
    while(c < 48 or c > 57) c = getchar();
    for(; (c > 47 and c < 58); c = getchar()) x = (x<<1) + (x<<3) + (c&15); //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

vector<vector<int>> grundy (1001, vector<int>(1001, 0));
void precompute() {
    for(int i = 0; i < 1001; ++i) {
        for(int j = 0; j < 1001; ++j) {
            vector<bool> mex = {0,0,0};

            if(i-1 >= 0) mex[grundy[i-1][j]] = 1;
            if(i-2 >= 0) mex[grundy[i-2][j]] = 1;
            if(j-1 >= 0) mex[grundy[i][j-1]] = 1;
            if(j-2 >= 0) mex[grundy[i][j-2]] = 1;
            if(i-1 >= 0 and j-1 >= 0) mex[grundy[i-1][j-1]] = 1;
            if(i-2 >= 0 and j-2 >= 0) mex[grundy[i-2][j-2]] = 1;

            int res_mex = 0;
            while(mex[res_mex]) res_mex++;   //mex -> maximum excludent
            grundy[i][j] = res_mex;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    //precompute();
    int t; fastInput(t);
    while(t--) {
        int k; fastInput(k);
        int ans = 0;
        for(int i = 0; i < k; ++i) {
            int n,m;
            fastInput(n); fastInput(m);
            //ans ^= grundy[n-1][m-1];
            ans ^= ((n+m-2)%3);   // checking the patterns in the grundy numbers from the matrix (n x m)    
        } 

        if(not ans) printf("EL\n");
        else printf("Light\n");
    }
    return 0;
}