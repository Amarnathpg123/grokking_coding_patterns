#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned,unsigned> puu;

void intersection_interval(vector<puu> &intervals1, vector<puu> &intervals2, vector<puu> &modified){
    if(not intervals1.size() or not intervals2.size()) return;

    size_t i = 0, j = 0;
    bool a_overlaps_b = 0, b_overlaps_a = 0;
    puu tmp;
    while(i < intervals1.size() and j < intervals2.size()){
        a_overlaps_b = intervals1[i].first >= intervals2[j].first and \
                        intervals1[i].first <= intervals2[j].second;
        
        b_overlaps_a = intervals2[j].first >= intervals1[i].first and \
                        intervals2[j].first <= intervals1[i].second;
        
        if(a_overlaps_b or b_overlaps_a){
            tmp.first = max(intervals1[i].first, intervals2[j].first);
            tmp.second = min(intervals1[i].second, intervals2[j].second);
            modified.push_back(tmp);
        }

        if(intervals1[i].second <= intervals2[j].second) i++;
        else j++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<puu> intervals1={}, intervals2={};
    vector<puu> modified={};
    unsigned n; puu tmp;
    cout << "Enter number of intervals for first set: " << endl; cin >> n;
    cout << "Enter the intervals as start end: " << endl;
    while(n--){
        cin >> tmp.first >> tmp.second; intervals1.push_back(tmp);
    }

    cout << "Enter number of intervals for second set: " << endl; cin >> n;
    cout << "Enter the intervals as start end: " << endl;
    while(n--){
        cin >> tmp.first >> tmp.second; intervals2.push_back(tmp);
    }

    printf("finding intersection of the two interval sets...\n");
    intersection_interval(intervals1, intervals2, modified);

    printf("Intersection intervals:\n");
    for(puu &tmp: modified) printf("%u %u\n", tmp.first, tmp.second);
    return 0;
}