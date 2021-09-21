#include <bits/stdc++.h>
using namespace std;

#define pcs pair<char, size_t>
#define umapcs unordered_map<char, size_t>

class CompFreq{
public:
    inline constexpr bool operator()(pcs const &a, pcs const &b) const {
        return a.second < b.second;
    }
};

void frequency_sort(string &s){
    if(s.size() < 3) cout << s;
    string t;
    umapcs umap;
    for(char &c: s) umap[c]++;

    priority_queue<pcs, vector<pcs>, CompFreq> pq;
    for(pcs const &i: umap) pq.push(i);

    while(pq.size()){
        pcs temp = pq.top();
        while(temp.second){ t.push_back(temp.first); temp.second--; }
        pq.pop();
    }
    cout << "Frequency sort: " << t << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    frequency_sort(s);
    return 0;
}