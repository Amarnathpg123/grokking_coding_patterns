#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned,unsigned> puu;

void print_intervals(vector<puu> &intervals){
    for(puu &tmp: intervals) printf("%u %u\n", tmp.first, tmp.second);
}

bool comp(puu &a, puu &b){
    return a.first < b.first;
}

void reduce_intervals(vector<puu> &intervals, vector<puu> &reduced){
    if(intervals.size() < 2) {reduced = intervals; return;}
    sort(intervals.begin(), intervals.end(), comp);
    puu tmp;

    size_t currentSeg = 0;
    while(currentSeg < intervals.size()){
        tmp = intervals[currentSeg++];
        while(currentSeg < intervals.size()){
            if(intervals[currentSeg].first < tmp.second){
                if(tmp.second < intervals[currentSeg].second) 
                    tmp.second = intervals[currentSeg++].second;
                else currentSeg++;
            }
            else break;
        }
        reduced.push_back(tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<puu> intervals={};
    vector<puu> reduced={};
    unsigned n; puu tmp;
    cout << "Enter number of intervals: " << endl; cin >> n;
    cout << "Enter the intervals as start end: " << endl;
    while(n--){
        cin >> tmp.first >> tmp.second; intervals.push_back(tmp);
    }

    printf("Reducing intervals...\n");
    reduce_intervals(intervals, reduced);

    printf("Intervals after Reduced are:\n"); print_intervals(reduced);
    
    return 0;
}