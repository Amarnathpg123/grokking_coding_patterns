#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned,unsigned> puu;

bool comp(puu &a, puu &b){
    return a.first < b.first;
}

class myComp{
    public:
    constexpr bool operator()(puu const&a, puu const&b) const noexcept{
        return a.second > b.second;
    }
};

unsigned minimum_rooms(vector<puu> &intervals){
    if(intervals.size() == 0) return 0;
    if(intervals.size() == 1) return 1;

    size_t rooms = 0;
    priority_queue<puu, vector<puu>, myComp> min_heap;
    sort(intervals.begin(), intervals.end(), comp);

    for(puu &interval: intervals){  
        while(min_heap.size() and interval.first >= min_heap.top().second)
            min_heap.pop();
        min_heap.push(interval);
        rooms = max(rooms, min_heap.size());
    }
    return rooms;
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

    printf("finding minimum rooms required...\n");

    printf("Minimum rooms required: %u", minimum_rooms(intervals));
    return 0;
}