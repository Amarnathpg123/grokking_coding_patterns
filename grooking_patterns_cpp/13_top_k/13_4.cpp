#include <bits/stdc++.h>
using namespace std;

unsigned minimum_cost_rope(vector<unsigned> &arr, priority_queue<unsigned, vector<unsigned>, greater<unsigned>> &pq){
    if(arr.size() < 2) return 0;

    unsigned ans = 0, temp = 0;
    while(pq.size() > 1){
        temp = pq.top(); pq.pop();
        temp += pq.top(); pq.pop();
        ans += temp;
        pq.push(temp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<unsigned> arr; 
    unsigned temp;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }

    priority_queue<unsigned, vector<unsigned>, greater<unsigned>> pq(arr.begin(), arr.end());
    printf("Minimumn cost for the biggest rope is: %u\n", minimum_cost_rope(arr, pq));

    return 0;
}