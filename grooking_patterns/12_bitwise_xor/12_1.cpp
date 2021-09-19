#include <bits/stdc++.h>
using namespace std;

long find_unique(vector<long> arr){
    if(arr.size() == 1) return arr[0];

    long ans = 0;
    for(size_t i = 0; i < arr.size(); ++i) ans ^= arr[i];

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n; cin >> n;
    vector<long> arr;
    long temp;
    while(n){ cin >> temp; arr.push_back(temp); n--; }

    printf("Unique value in the array is: %ld\n", find_unique(arr));
    return 0;
}