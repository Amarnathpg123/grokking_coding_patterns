#include <bits/stdc++.h>
using namespace std;

unordered_set<string> utility(string str) {
    unordered_set<string> curr_set;
    if(str.length() < 2) { curr_set.emplace(str); return curr_set;}
    if(str.length() == 2) {
        curr_set.emplace(str); 
        reverse(str.begin(), str.end());
        curr_set.emplace(str);
        return curr_set;
    }

    int n = str.length();
    for(int i = 0; i < n; ++i) {
        string temp = str.substr(0, i)+str.substr(i+1, n-i-1);
        for(auto &res_str: utility(temp))
            curr_set.emplace(str[i]+res_str);
    }

    return curr_set;
}

unordered_set<string> findPermutations(string &str) {
    if(str.length() < 2) { 
        unordered_set<string> curr_set;
        curr_set.emplace(str); 
        return curr_set;
    }
    return utility(str);
}

void printPermutations(string &str) {
    for(auto &str: findPermutations(str))
        cout << str << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string str;
    cin >> str;
    printPermutations(str);
    return 0;
}