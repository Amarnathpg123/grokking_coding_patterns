#include <bits/stdc++.h>
using namespace std;

void findNextGreaterPermutation(vector<int> &arr) {
    if(arr.size() < 2) return;
    
    int lastGreater = -1;

    for(int i = 1; i < arr.size(); ++i) 
        if(arr[i]>arr[i-1]) lastGreater = i;

    if(lastGreater == -1)  { //decreasing sequence 
        for(int i = 0; i < int(arr.size()/2); ++i) 
           swap(arr[i], arr[arr.size()-1-i]);
        return;
    }

    int index = lastGreater;
    for(int i = lastGreater+1; i < arr.size(); ++i)
        if(arr[lastGreater-1]<arr[i]) index= i;

    swap(arr[index], arr[lastGreater-1]);
    sort(arr.begin()+lastGreater, arr.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = { 1,2,3,5,4,2 };
    findNextGreaterPermutation(arr);
    
    for(auto &num: arr) cout << num << " ";
    cout << endl;
    return 0;
}