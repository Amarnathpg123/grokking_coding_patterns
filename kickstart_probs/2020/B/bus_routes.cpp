#include <bits/stdc++.h>
using namespace std;

#define us unsigned long
#define ll long long

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

void solve(vector<us> &arr, us D, us &ans){
    if(arr.size() < 1) { ans = D; return; }
    
    ll i = arr.size()-1; 
    while(i >= 0){
        arr[i] = (D/arr[i])*arr[i];   
        D = arr[i--];
    }
    ans = arr[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    us T; fastInput<us>(T);
    for(us i = 1; i <= T; ++i){
        us N, D, temp; fastInput<us>(N); fastInput<us>(D);
        vector<us> arr;
        while(N){
            fastInput<us>(temp); arr.push_back(temp);
            N--;
        }
        us ans = 0;
        solve(arr, D, ans);
        printf("Case #%lu: %lu\n", i, ans);
    }
    return 0;
}