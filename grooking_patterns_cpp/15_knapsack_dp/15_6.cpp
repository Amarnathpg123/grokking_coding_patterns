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

u CountSignWays(vector<u> &arr, u const &target) {  //same as number of subsets with sum as (total+target)/2
    if(arr.size() == 1) return arr[0] == target;

    u sum = accumulate(arr.begin(), arr.end(), 0);
    if(not (sum+target)%2) return 0;
    sum += target; sum >>= 1;

    vector<u> dp(sum+1, 0);
    dp[0] = 1;
    for(size_t i = 0; i < arr.size(); ++i)
        for(u s = sum; s > 0; --s)
           if(s >= arr[i]) dp[s] += dp[s-arr[i]];
    return dp[sum];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    u n, sum; FastInput(n); FastInput(sum);
    vector<u> arr; u temp;
    while(n) {
        FastInput(temp); arr.emplace_back(temp);
        n--;
    }

    printf("Total number of ways to assign + or - to get zero sum: %u\n", CountSignWays(arr, sum));
    return 0;
}