#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<unsigned,unsigned>,unsigned> triplet;

constexpr bool comp(triplet const& a, triplet const& b){
    return a.first.first < b.first.first;
}

class myComp{
    public:
    constexpr bool operator()(triplet const& a, triplet const& b) const noexcept{
        return a.first.second > b.first.second;
    }
};

unsigned max_load(vector<triplet> &processes){
    if(processes.size() == 0) return 0;
    if(processes.size() == 1) return processes[0].second;

    unsigned maxLoad = 0, currentLoad = 0;
    priority_queue<triplet, vector<triplet>, myComp> min_heap;
    sort(processes.begin(), processes.end(), comp);

    for(triplet &process: processes){  
        while(min_heap.size() and process.first.first >= min_heap.top().first.second)
            currentLoad -= min_heap.top().second, min_heap.pop();
        min_heap.push(process);
        currentLoad += process.second;
        maxLoad = max(maxLoad, currentLoad);
    }
    return maxLoad;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<triplet> processes={};
    size_t n; triplet tmp;
    cout << "Enter number of processes: " << endl; cin >> n;
    cout << "Enter the processes as start end load: " << endl;
    while(n--){
        cin >> tmp.first.first >> tmp.first.second >> tmp.second; processes.push_back(tmp);
    }

    printf("finding max CPU load...\n");

    printf("Maximum CPU load: %u", max_load(processes));
    return 0;
}