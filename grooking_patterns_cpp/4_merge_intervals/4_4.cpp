#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned,unsigned> puu;

bool comp(puu &a, puu &b){
    return a.first < b.first;
}

bool check_overlap(vector<puu> &intervals){
    if(intervals.size() < 1) return false;

    sort(intervals.begin(), intervals.end(), comp);

    for(size_t i = 0; i < intervals.size(); ++i)
        if(intervals[i].first < intervals[i-1].second) return true;
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<puu> intervals={};
    unsigned n; puu tmp;
    cout << "Enter number of intervals: " << endl; cin >> n;
    cout << "Enter the intervals as start end: " << endl;
    while(n--){
        cin >> tmp.first >> tmp.second; intervals.push_back(tmp);
    }

    printf("finding overlap of the intervals...\n");
    if(check_overlap(intervals)) printf("Yes overlap, person can't attend all\n");
    else printf("No overlap, person can attend all\n");

    return 0;
}