#include <bits/stdc++.h>
using namespace std;

class KthLargestNumberInStream{
    priority_queue<long, vector<long>, greater<long>> pq;
    size_t k;
public:
    KthLargestNumberInStream(vector<long> &arr, size_t const &k_): k(k_){
        for(long const &num: arr){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }

    long add(long const &num){
        pq.push(num);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, k; cin >> n >> k;
    vector<long> arr; long temp;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;    
    }
    KthLargestNumberInStream stream(arr, k);
    cin >> temp;
    printf("%luth largest number after adding %ld is: %ld\n", k, temp, stream.add(temp));
    cin >> temp;
    printf("%luth largest number after adding %ld is: %ld\n", k, temp, stream.add(temp));
    cin >> temp;
    printf("%luth largest number after adding %ld is: %ld\n", k, temp, stream.add(temp));
    return 0;
}