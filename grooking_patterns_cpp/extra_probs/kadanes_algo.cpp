#include <bits/stdc++.h>
using namespace std;

void kadanes_algo(vector<long> &arr, long &sum){
    long meh = 0, msf = INT32_MIN;
    for(long &num: arr){
        meh += num;
        if(meh < num) meh = num;
        if(msf < meh) msf = meh;
    }
    sum = msf;
}

void kadanes_algo1(vector<long> &arr, long &sum){
    long meh = 0, msf = INT32_MIN;
    for(long &num: arr){
        meh += num;
        if(msf < meh) msf = meh;
        if(meh < 0) meh = 0;
    }
    sum = msf;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // size_t n; cin >> n;
    // vector<long> arr; long temp;
    // while(n){
    //     cin >> temp; arr.push_back(temp);
    //     n--;
    // }

    vector<long> arr = {-1,-1,-1,-1,-1};
    //{-2, -3, 4, -1, -2, 1, 5, -3};
    //size_t l = 0, r = arr.size()-1;
    long sum; //accumulate(arr.begin(), arr.end(), 0);
    kadanes_algo(arr, sum);
    cout << "Continuous subarray with max sum is: " << sum << endl;

    kadanes_algo1(arr, sum);
    cout << "Continuous subarray with max sum is: " << sum << endl;
    // printf("Continuous subarray with max sum is: %ld (from %llu and %llu)\n", sum, l, r);
    return 0;
}