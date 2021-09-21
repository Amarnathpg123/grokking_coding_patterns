#include <bits/stdc++.h>
using namespace std;

long x;

class CompK{
public:
    inline bool operator()(long const &a, long const &b) const {
        return abs(a-x) < abs(b-x);
    }
};

size_t binary_search(vector<long> &arr){
    size_t l = 0, r = arr.size()-1;
    while(l <= r){
        size_t mid = l + (r-l)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) r = mid-1;
        else l = mid+1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, k;
    vector<long> arr; long temp;
    cin >> n >> k >> x;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }  
    assert(arr.size() >= k);

    priority_queue<long, vector<long>, CompK> pq;
    
    size_t index = binary_search(arr);

    for(long i = max(long(0),long(index-k)); i <= min(arr.size()-1, (index+k)); ++i){
        pq.push(arr[i]);
        if(pq.size() > k)
            pq.pop();
    }

    printf("%lu nearest elements to %ld are: ", k , x);
    while(pq.size()){
        printf("%ld ", pq.top());
        pq.pop();
    }
    printf("\n");

    return 0;
}