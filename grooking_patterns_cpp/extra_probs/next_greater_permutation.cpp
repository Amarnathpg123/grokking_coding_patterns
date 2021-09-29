#include <bits/stdc++.h>
using namespace std;

void findNextGreaterPermutation(vector<int> &arr) {
    if(arr.size() < 2) return;
    
    int i = 0;

    for(i = arr.size()-1; i > 0; --i) 
        if(arr[i]>arr[i-1]) break;

    //if i == 0 no next greater perm is possible

    if(i != 0) {
        for(int j = arr.size()-1; j > i; j--)
            if(arr[j] > arr[i-1]) {
                swap(arr[i-1], arr[j]);
                break;
            }
    }

    reverse(arr.begin()+i, arr.end());
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