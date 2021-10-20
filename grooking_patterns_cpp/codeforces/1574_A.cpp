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

vector<vector<string>> dp;

vector<string> rec(int n) {
    if(dp[n][0] != "-1") return dp[n];

    if(n == 1) return dp[1] = {"()"};

    unordered_set<string> uset = {};

    for(string &s: rec(n-1)) {
        string t1 = "(", t2 = "()", t3 = "";

        t1 += s, t2 += s, t3 += s;
        t1 += ")", t3 += "()";

        uset.emplace(t1);
        uset.emplace(t2);
        uset.emplace(t3);

        if(uset.size()>n) break;
    }

    dp[n].clear();
    dp[n].reserve(uset.size());
    
    int k = n;
    for (auto it = uset.begin(); it != uset.end(); it++) 
        if(k-- > 0) dp[n].push_back(move(*it));

    return dp[n];
}

void preprocess() {
    rec(10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t, n; fastInput(t);
    dp.resize(51, vector<string>(1,{"-1"}));
    //preprocess();
    while(t--) {
        fastInput(n);
        //for(string &s: dp[n]) cout << s << endl;   

        for(int i = 1; i <= n; ++i) 
            cout << string(i, '(') + string(i, ')') + string(n-i, '(') + string(n-i, ')') + "\n";
    }
    return 0;
}