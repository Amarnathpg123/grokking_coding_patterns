#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dict = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
void wordBreakUtility(string, int, string);

void wordBreak(string str) {
    wordBreakUtility(str, str.length(), "");
}

void wordBreakUtility(string s, int n, string res) {
    for(int i = 1; i <= n; ++i) {
        string prefix = s.substr(0,i);

        if(dict.count(prefix)) {
            if(i == n) {
                res += prefix;
                cout << res << endl;
                return;
            }
            wordBreakUtility(s.substr(i), n-i, res+prefix+" ");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    wordBreak("iloveicecreamandmango");
    return 0;
}