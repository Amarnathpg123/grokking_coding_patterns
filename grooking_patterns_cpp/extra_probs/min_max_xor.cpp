#include <bits/stdc++.h>
using namespace std;

int findMinXor(vector<int> &arr) {
    int xr = INT_MAX;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size()-1; ++i) xr = min(xr, arr[i]^arr[i+1]);

    return xr;
}

int findMaxXor(vector<int> &arr) {
    int maxx = 0, mask = 0, n = arr.size();
 
    set<int> se;
 
    for (int i = 30; i >= 0; i--) {
 
        // set the i'th bit in mask
        // like 100000, 110000, 111000..
        mask |= (1 << i);
 
        for (int i = 0; i < n; ++i) {
 
            // Just keep the prefix till
            // i'th bit neglecting all
            // the bit's after i'th bit
            se.insert(arr[i] & mask);
        }
 
        int newMaxx = maxx | (1 << i);
 
        for (int prefix : se) {
 
            // find two pair in set
            // such that a^b = newMaxx
            // which is the highest
            // possible bit can be obtained
            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }
 
        // clear the set for next
        // iteration
        se.clear();
    }
 
    return maxx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = { 25, 10, 2, 8, 5, 3 };
    cout << "minimum xor of a pair in the array: " << findMinXor(arr) << endl;
    cout << "maximum xor of a pair in the array: " << findMaxXor(arr) << endl;
    return 0;
}