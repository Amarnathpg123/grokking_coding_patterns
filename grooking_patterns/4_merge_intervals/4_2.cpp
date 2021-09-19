#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned,unsigned> puu;

void insert_interval(vector<puu> &intervals, vector<puu> &modified, puu &new_interval){
    if(intervals.size()<1) {intervals.push_back(new_interval); return;}
    size_t i = 0;
    
    while(i < intervals.size() and intervals[i].second < new_interval.first)
        modified.push_back(intervals[i++]);

    while(i < intervals.size() and intervals[i].first <= new_interval.second){
        new_interval.first = min(new_interval.first, intervals[i].first);
        new_interval.second = max(new_interval.second, intervals[i++].second);
    }
    modified.push_back(new_interval);

    while(i < intervals.size()) modified.push_back(intervals[i++]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<puu> intervals={}, modified={};
    unsigned n; puu tmp;
    cout << "Enter number of intervals: " << endl; cin >> n;
    cout << "Enter the intervals as start end: " << endl;
    while(n--){
        cin >> tmp.first >> tmp.second; intervals.push_back(tmp);
    }

    cout << "Enter the new interval that needs to be inserted: " << endl; cin >> tmp.first >> tmp.second;

    printf("Inserting the new interval...\n");
    insert_interval(intervals, modified, tmp);

    printf("After merge intervals:\n");
    for(puu &tmp: modified) printf("%u %u\n", tmp.first, tmp.second);
    return 0;
}