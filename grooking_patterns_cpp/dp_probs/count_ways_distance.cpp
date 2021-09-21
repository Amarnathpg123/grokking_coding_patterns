#include <bits/stdc++.h>
using namespace std;

void count_ways(size_t &n){
    vector<size_t> ways{1,1,2};

    for(size_t i = 3; i <= n; ++i)
        ways[i%3] = ways[(i-3)%3]+ways[(i-2)%3]+ways[(i-1)%3];
    
    printf("Number of ways to cover the distance %llu is: %llu\n", n, ways[n%3]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    count_ways(n);
    return 0;
}