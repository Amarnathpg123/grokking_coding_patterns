#include <bits/stdc++.h>
using namespace std;

#define REP(i,k,n) for(size_t i = k; i <= n; ++i)
#define u unsigned
#define puu pair<u, u>
#define vpuu vector<puu>

template <typename T>
void FastInput(T &x) {
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c = getchar(); }
    while(c < 48 or c > 57) c = getchar();
    for(; (c > 47 and c < 58); c = getchar()) x = (x<<1) + (x<<3) + (c&15); //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

//bottom-up approach
void KnapsackDp(vpuu &items, u &W, u &max_val) {
    vector<u> dp(W+1, 0);

    REP(i, 1, items.size())
        for(u w = W; w > 0; --w)
            if(items[i-1].first <= w)
                dp[w] = max(dp[w], dp[w-items[i-1].first]+items[i-1].second);

    max_val = dp[W];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    u n, W, max_val = 0;
    cout << "Enter number of items: " << endl; FastInput(n);
    cout << "Enter the knapsack weight capacity: " << endl; FastInput(W);

    vpuu items; puu temp;
    cout << "Enter the weight and value of the items: " << endl;
    while(n) {
        FastInput(temp.first); FastInput(temp.second);
        items.emplace_back(temp);
        n--;
    }

    KnapsackDp(items, W, max_val);
    cout << "Maximum value of the items that can fit into is (dp method): " << max_val << endl;
    return 0;
}
