#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &arr) {
    int max_overall = arr[0];
    int max_end_here = arr[0], min_end_here = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
        int temp = max_end_here;
        max_end_here = max({arr[i], max_end_here*arr[i], min_end_here*arr[i]});
        min_end_here = min({arr[i], temp*arr[i], min_end_here*arr[i]});
        max_overall = max(max_overall, max_end_here);
    }
    return max_overall;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {-3, 2, -4, 6, 0, -8, 5};
    cout << "maximum product of subarray: " << maxProductSubarray(arr) << endl;
    return 0;
}