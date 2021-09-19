#include <bits/stdc++.h>
using namespace std;

void lis_bin_search(vector<long> &arr){
    // O(nlongn) time
    if(arr.size() < 2){
        cout << "Longest increasing subsequence is: " << arr.size() << endl;
        return;
    }

    vector<long> lis;
    lis.push_back(arr[0]);
    for(size_t i = 1; i < arr.size(); ++i){
        if(lis.back() < arr[i])
            lis.push_back(arr[i]);
        else{
            size_t idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    cout << "Longest increasing subsequence is: " << lis.size() << endl;
}

void lis_dp(vector<long> &arr){
    // O(nxn) time
    vector<size_t> lis(arr.size(),1);

    for(size_t i = 1; i < arr.size(); ++i){
        for(size_t j = 0; j < i; ++j){
            if(arr[i] > arr[j] and lis[i] < (lis[j]+1))
                lis[i] = lis[j]+1;
        }
    }

    cout << "Longest increasing subsequence is: " << *max_element(lis.begin(), lis.end()) << endl;
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
    lis_bin_search(arr);

    lis_dp(arr);
    return 0;
}