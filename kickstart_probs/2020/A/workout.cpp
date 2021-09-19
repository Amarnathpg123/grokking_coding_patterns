    #include <bits/stdc++.h>
using namespace std;

#define us unsigned
#define vu vector<us>

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

void find_diff_optimum(vu &M, us const &K, us &d_opt){
    if(not M.size()) return;
    
    unordered_map<us, us> umap;
    us l = 1, r = 0;

    for(us i = 1; i < M.size(); ++i){   
        us temp = abs(long(M[i] - M[i-1]));
        r = max(r, temp);
        umap[temp]++;
    }

    if(K == 0){ d_opt = r; return; }
    if(K == 1){
        umap[unsigned(r/2)]++; umap[r-unsigned(r/2)]++;
        umap[r]--;
        d_opt = 0;
        for(auto &i: umap)
            if(i.second) d_opt = max(d_opt, i.first);
        return;
    }

    while(l < r){
        us mid = l + (r-l)/2, k = 0;
        for(auto &i: umap){
            k += ((i.first-1)/mid)*i.second;
            if(k > K) {l = mid+1; break;}
        }
        if(k <= K) r = mid; 
    }
    d_opt = l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    us T; fastInput<us>(T);
    for(us i = 1; i <= T; ++i){
        us N, K, temp, d_opt = 0; fastInput<us>(N); fastInput<us>(K);
        vu M;
        while(N){
            fastInput<us>(temp); M.push_back(temp);
            N--;
        }
        find_diff_optimum(M, K, d_opt);
        printf("Case #%u: %u\n", i, d_opt);
    }
    return 0;
}

/*
1
3 1
100 200 230  Case #1: 50

3
5 2
10 13 15 16 17      Case #1: 2
5 6
9 10 20 26 30       Case #2: 3
8 3
1 2 3 4 5 6 7 10    Case #3: 1

*/