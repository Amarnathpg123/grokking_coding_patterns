#include <bits/stdc++.h>
using namespace std;

size_t changePossibilities(int amount, const vector<int>& denom) {
    vector<int> dp(denom.size()+1, 1);
    dp[0] = 0;

    if(amount == 0) return 1;
    if(denom.size() == 0) return 0;

    for(int i = 1; i < amount+1; ++i) {
        for(int j = 0; j < denom.size(); ++j) {
           dp[j]  +=  
        }
    }
    return dp[denom.size()];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> denom = {1, 2, 3};
    int amount = 4;
    cout << changePossibilities(amount, denom) << endl;
    return 0;
}