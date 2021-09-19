#include <bits/stdc++.h>
using namespace std;

#define u unsigned
#define puu pair<u,u>
#define vpuu vector<puu>

size_t RussianDollDp(vpuu &envs) {
    if(envs.size() < 2) return envs.size();

    sort(envs.begin(), envs.end(), [&](const puu &a, const puu &b) -> bool{
            if(a.first < b.first and a.second < b.second) return true;
            else if(a.first == b.first) return a.second > b.second;  //if a.w == b.w the sort in descending of a.h and b.h
            return false;
            });
    vector<puu *> lis;
    lis.push_back(&envs[0]);

    //LIS problem
    for(size_t i = 1; i < envs.size(); ++i){
        if(lis.back()->first < envs[i].first and lis.back()->second < envs[i].second)
            lis.push_back(&envs[i]);
        else{
            size_t idx = lower_bound(lis.begin(), lis.end(), &envs[i], [&](puu *a, puu *b) -> bool {
                return (a->first < b->first and a->second < b->second); })-lis.begin();
            lis[idx] = &envs[i];
        }
    }
    return lis.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vpuu envelopes;
    puu t;
    while(n) {
        cin >> t.first >> t.second;
        envelopes.push_back(t);
        n--;
    }

    printf("Maximum no. envelopes than can be stacked one inside the other: %llu\n", RussianDollDp(envelopes));
    return 0;
}