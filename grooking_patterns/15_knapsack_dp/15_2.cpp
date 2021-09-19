#include <bits/stdc++.h>
using namespace std;

#define u unsigned

template <typename T>
void FastInput(T &x) {
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c = getchar(); }
    while(c < 48 or c > 57) c = getchar();
    for(; (c > 47 and c < 58); c = getchar()) x = (x<<1) + (x<<3) + (c&15); //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

bool IsEquipartitioned(vector<u> &arr) {
    if(arr.size() < 2)  return false;
    u sum = accumulate(arr.begin(), arr.end(), 0);
    if(not sum%2) return false;
    sum >>= 1;

    vector<bool> dp(sum+1, 0);
    dp[0] = true;

    for(size_t i = 0; i < arr.size(); ++i)
        for(u s = sum; s > 0; --s)
            if(s >= arr[i])
                dp[s] = dp[s] or dp[s-arr[i]];
    
    return dp[sum];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    u n; FastInput(n);
    vector<u> arr; u temp;
    while(n) {
        FastInput(temp); arr.emplace_back(temp);
        n--;
    }

    if(IsEquipartitioned(arr)) printf("Yes, Array can be partitioned with equal sum\n");
    else printf("No, Array can not be partitioned with equal sum\n");
    return 0;
}