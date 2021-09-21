#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> umap;

bool isAnagram(string &A, string &B) {
    int xr = 0;
    for(auto &c: A) xr ^= c;
    for(auto &c: B) xr ^= c;

    return xr == 0;
}

bool utility(string A, string B) {
    if(A.length() != B.length()) return 0;
    if(A.compare(B) == 0) return 1;

    int n = A.size();
    if(n == 0) return 1;

    if(not isAnagram(A, B)) return 0;

    string key = A + " " + B;
    if(umap.find(key) != umap.end()) return umap[key];

    bool flag = 0;

    for(int k = 1; k < n; ++k) {
        bool cond1 = utility(B.substr(0,k), A.substr(0,k)) and utility(B.substr(k, n-k), A.substr(k, n-k));
        bool cond2 = utility(B.substr(0,k), A.substr(n-k, k)) and utility(B.substr(k, n-k), A.substr(0, n-k));

        flag = cond1 or cond2;
        if(flag) break;
    }

    umap[key] = flag;
    return flag;

}

bool isScrambled(string &A, string &B) {
    if(A.length() != B.length()) return 0;

    if(A.compare(B) == 0) return 1;
    if(not isAnagram(A, B)) return 0;

    return utility(A, B);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    if(isScrambled(A, B)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}