#include <bits/stdc++.h>
using namespace std;

int solve(int mask, int cur, vector<int> &nums, vector<int> &dp) {
    if(dp[mask] != -1) return dp[mask];

    int ans = 0;
    for(int i = 0; i < nums.size(); ++i)
        if((mask&(1<<i)) == 0 and (nums[i]&cur) == 0)
            ans = max(ans, solve(mask|(1<<i), cur|nums[i], nums, dp)+__builtin_popcount(nums[i]));
    return dp[mask] = ans;
}

void dpBitMask(vector<string> &arr, int &ans) {
    vector<int> nums(arr.size(), 0);

    for(int i = 0; i < arr.size(); ++i) {
        int res = 0;
        for(int j = 0; j < arr[i].size(); ++j) {
            int k = arr[i][j] - 'a';
            if(not (res & (1<<k))) res = res^(1<<k);
            else { res = 0; break;}
        }
        nums[i] = res;
    }
    if(arr.size() == 1) { ans = __builtin_popcount(nums[0]); return; }

    vector<int> dp(1<<16, -1);
    ans = solve(0, 0, nums, dp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<string> arr = {"cha","rr","act","ers"};
    int ans = 0;
    dpBitMask(arr, ans);
    cout << "Max length: " << ans << endl;
    return 0;
}


