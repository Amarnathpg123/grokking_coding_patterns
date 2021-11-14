//https://practice.geeksforgeeks.org/problems/divide-and-subtract-game2253/1/?category%5B%5D
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

bool whoWins(int const &n) {
    if(n == 1) return 0;
    vector<bool> dp(n+1, 0);

    for(int i = 2; i < n; ++i) {
        for(int j = 2; j < 6; ++j) {
            if(dp[i/j] == 0) dp[i] = 1;
            if(i-j >= 0 and dp[i-j] == 0) dp[i] = 1;
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; fastInput(t);
    while(t--) {
        int n; fastInput(n);
        whoWins(n)?printf("Jon"): printf("Arya");
    }
    return 0;
}