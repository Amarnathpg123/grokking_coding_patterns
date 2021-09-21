#include <bits/stdc++.h>
using namespace std;

#define puu pair<unsigned, unsigned>
#define vpuu vector<puu>
#define vvl vector<vector<long>>

//top-down approach
long recursive_knapsack(vpuu &items, vvl &dp, size_t i, unsigned j){
    if(i == 0 or j == 0) return dp[i][j] = 0; 

    if(dp[i-1][j] == -1) dp[i-1][j] = recursive_knapsack(items, dp, i-1, j);

    if(items[i].first > j) dp[i][j] = dp[i-1][j];
    else{
        if(dp[i-1][j-items[i].first] == -1)
            dp[i-1][j-items[i].first] = recursive_knapsack(items, dp, i-1, j-items[i].first);
        dp[i][j] = max(dp[i-1][j], long(dp[i-1][j-items[i].first]+items[i].second));
    }
    return dp[i][j];
}

void find_max_value_knapsack(vpuu &items, unsigned const &W, unsigned &max_val){
    vvl dp(items.size()+1, vector<long> (W+1, -1)); //2d vector initialisation
    recursive_knapsack(items, dp, items.size(), W);
    if(dp[items.size()][W] > 0) max_val = dp[items.size()][W];
}

//bottom-up approach
void knapsack_space_optimised(vpuu &items, unsigned const &W, unsigned &max_val){
    vector<unsigned> dp(W+1, 0);
    if(!W or !items.size()) { max_val = 0; return; }

    for(size_t i = 1; i <= items.size(); ++i){
        for(unsigned w = W; w > 0; --w){
            if(items[i-1].first <= w)
                dp[w] = max(dp[w], dp[w-items[i-1].first]+items[i-1].second); // dp[w] of i items is updating with dp[w] of i-1 items
                // and d[w-wi]+vi
        }
    }
    max_val = dp[W];
}

template <typename T>
void FastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + (c&15); //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    unsigned n, W, max_val = 0;
    cout << "Enter number of items: " << endl; FastInput(n);
    cout << "Enter the knapsack weight capacity: " << endl; FastInput(W);

    vpuu items; puu temp;
    cout << "Enter the weight and value of the items: " << endl;
    while(n) {
        FastInput(temp.first); FastInput(temp.second);
        items.emplace_back(temp);
        n--;
    }

    find_max_value_knapsack(items, W, max_val);
    cout << "Maximum value of the items that can fit into is (dp method): " << max_val << endl;

    knapsack_space_optimised(items, W, max_val);
    cout << "Maximum value of the items that can fit into is (dp space optimised method): " << max_val << endl;

    return 0;
}

/**
 * consider this input
10 67  max_val(10,67) = 1270
23 505
26 352
20 458
18 220
32 354
27 414
29 498
26 545
30 473
27 543

**/