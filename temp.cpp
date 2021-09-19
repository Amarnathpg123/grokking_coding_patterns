#include <bits/stdc++.h>
using namespace std;

int rec(int i, vector<int> &arr, vector<int> &dp, unordered_map<int, vector<int>> &umap) {
    printf("%d ", i);
    if(dp[i] != -1) return dp[i];

    int temp = 0;
    if(i-1 >= 0) {
        if(dp[i-1] == -1) dp[i-1] = rec(i-1, arr, dp, umap);
        temp = min(temp, dp[i-1]);
    }

    if(i+1 < arr.size()) {
        if(dp[i+1] == -1) dp[i+1] = rec(i+1, arr, dp, umap);
        temp = min(temp, dp[i+1]);
    }

    for(int j = 0; j < umap[arr[i]].size(); ++j) {
        int idx = umap[arr[i]][j];
        if(dp[idx] == -1) dp[idx] = rec(idx, arr, dp, umap); 
        temp = min(temp, dp[idx]);
    }

    return dp[i] = temp;
}

int jumpGame(std::vector<int>& arr) {
    if(arr.size() <= 1) return 0;

    unordered_map<int, vector<int>> umap;
    for(int i = 0; i < arr.size(); ++i) umap[arr[i]].emplace_back(i);

    vector<int> dp(arr.size(), -1);
    dp[arr.size()-1] = 0;
    dp[arr.size()-2] = 1;

    rec(0,arr,dp, umap);
    return dp[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {23, 11, 44, 5, 6, 9, 11, 16};
    printf("minimum steps: %d\n", jumpGame(arr));
    return 0;
}