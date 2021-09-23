#include <bits/stdc++.h>
using namespace std;

int maxAreaHist(vector<int> &dp) {
    if(accumulate(dp.begin(), dp.end(), 0) == 0) return 0;

    vector<int> left(dp.size(), 0);
    vector<int> right(dp.size(), 0);
    int max_area = 0;

    stack<int> sk;
    for(int i = 0; i < dp.size(); ++i) {
        if(sk.empty()) sk.push(i), left[i] = 0;
        else {
            while(not sk.empty() and dp[i] <= dp[sk.top()]) sk.pop();
            left[i] = sk.empty()? 0: sk.top()+1;
            sk.push(i);
        }
    }

    while(not sk.empty()) sk.pop();

    for(int i = dp.size()-1; i >= 0; --i) {
        if(sk.empty()) sk.push(i), right[i] = dp.size()-1;
        else {
            while(not sk.empty() and dp[i] <= dp[sk.top()]) sk.pop();
            right[i] = sk.empty()? dp.size()-1: sk.top()-1;
            sk.push(i);
        }
    }

    for(int i = 0; i < dp.size(); ++i) max_area = max(max_area, (right[i]-left[i]+1)*dp[i]);

    return max_area;
}

int findMaximumArea(vector<vector<bool>> &m) {
    if(m.size()*m[0].size() == 0) return 0;
    vector<int> dp(m[0].size(), 0);

    int max_area = 0;
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[0].size(); ++j) {
            if(m[i][j] == 1) dp[j]++;
            else dp[j] = 0;
        }

        max_area = max(max_area, maxAreaHist(dp));
    }
    return max_area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<bool>> matrix = {{1,0,1,0,0}, {1,0,1,1,1}, {1,1,1,1,1}, {1,0,0,1,0}};
    printf("Maximum rectagular area in the given matrix: %d\n", findMaximumArea(matrix));
    return 0;
}