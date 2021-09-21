#include <bits/stdc++.h>
using namespace std;

void kadanes_algo(vector<long> &arr, size_t &l, size_t &r, long &sum){
    long meh = 0, msf = INT32_MIN;
    size_t index = 0;
    for(long &num: arr){
        meh += num;
        if(meh < num) meh = num, l = index;
        if(msf < meh) msf = meh, r = index;
        index++;
    }
    sum = msf;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    size_t n; cin >> n;
    vector<long> arr; long temp;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }

    size_t l = 0, r = arr.size()-1;
    long sum = accumulate(arr.begin(), arr.end(), 0);
    kadanes_algo(arr, l, r, sum);
    printf("Continuous subarray with max sum is: %ld (from %llu and %llu)\n", sum, l, r);
    return 0;
}