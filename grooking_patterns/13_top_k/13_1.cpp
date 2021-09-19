#include <bits/stdc++.h>
using namespace std;

void find_top_k(vector<long> arr, size_t const &k, priority_queue<long, vector<long>, greater<long>> &pq){
    if(arr.size() == k) return;

    for(size_t i = k; i < arr.size(); ++i){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
}

void print_pq(priority_queue<long, vector<long>, greater<long>> &pq){
    while(pq.size()){
        printf("%ld ", pq.top());
        pq.pop();
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, k; 
    cout << "Enter no. elements and k: " << endl; cin >> n; cin >> k;
    vector<long> arr; long temp;
    cout << "Enter the elements: " << endl;
    while(n){
        cin >> temp; arr.push_back(temp); n--;
    }
    assert(arr.size() > k);
    priority_queue<long, vector<long>, greater<long>> pq(arr.begin(), arr.begin()+k);
    find_top_k(arr, k, pq);
    printf("Top %lu elements are: ", k);
    print_pq(pq);
    return 0;
}