#include <bits/stdc++.h>
using namespace std;

#define vvu vector<vector<unsigned>>
#define vvl vector<vector<long>>

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

long recursive_max_beauty(vvl &dp, vvu &sum, unsigned i, long j){
    if(i == 0 or j <= 0 ){
        if(j < 0) j = 0;
        dp[i][j] = 0;
        return dp[i][j];
    }

    unsigned temp = min(unsigned(sum[1].size()-1), unsigned(j));
    for(unsigned x = 0; x <= temp; ++x){
        if(dp[i-1][j-x] == -1)
            dp[i-1][j-x] = recursive_max_beauty(dp, sum, i-1, j-x);
        dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x]);
    }
    return dp[i][j];
}

void find_max_beauty(vvu &plates, unsigned &P, unsigned &max_beauty){
    vvu sum(plates.size(), vector<unsigned>(plates[1].size(),0));
    for(unsigned i = 1; i <= plates.size()-1; ++i)
        sum[i][1] = plates[i][1];

    for(unsigned i = 1; i <= plates.size()-1; ++i){
        for(unsigned j = 2; j <= plates[1].size()-1; ++j)
            sum[i][j] += sum[i][j-1]+plates[i][j];
    }

    vvl dp(plates.size(), vector<long>(P+1,-1));
    recursive_max_beauty(dp, sum, plates.size()-1, P);
    if(dp[plates.size()-1][P] > 0) max_beauty = dp[plates.size()-1][P];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unsigned T; fastInput<unsigned>(T);
    for(unsigned i = 1; i <= T; ++i){
        unsigned N, K, P, max_beauty = 0; fastInput<unsigned>(N);
        fastInput<unsigned>(K); fastInput<unsigned>(P);

        if(not N or not P or not K){
            printf("Case #%u: %u\n", i, max_beauty);
            continue;
        }

        vvu plates(N+1, vector<unsigned>(K+1,0));
        for(unsigned j = 1; j <= N; ++j){
            for(unsigned k = 1; k <= K; ++k)
                fastInput<unsigned>(plates[j][k]);
        }
        find_max_beauty(plates, P, max_beauty);
        printf("Case #%u: %u\n", i, max_beauty);
    }
    return 0;
}

/*
2
2 4 5
10 10 100 30
80 50 10 50    ###Case 1: 250
3 2 3
80 80
15 50
20 10         ###Case 2: 180
*/