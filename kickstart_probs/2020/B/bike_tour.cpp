#include <bits/stdc++.h>
using namespace std;

#define us unsigned

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

void solve(vector<us> &arr, us &ans){
    if(arr.size() < 3) return;

    for(us i = 2; i < arr.size(); ++i)
        if(arr[i-2] < arr[i-1] and arr[i-1] > arr[i]) ans++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    us T; fastInput<us>(T);
    for(us i = 1; i <= T; ++i){
        us N, temp; fastInput<us>(N);
        vector<us> arr;
        while(N){
            fastInput<us>(temp); arr.push_back(temp);
            N--;
        }
        us ans = 0;
        solve(arr, ans);
        printf("Case #%u: %u\n", i, ans);
    }
    return 0;
}