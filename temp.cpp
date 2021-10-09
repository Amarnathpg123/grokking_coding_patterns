#include <bits/stdc++.h>
using namespace std;

vector<int> printKPascalTRow(int &k) {
    if(k == 1) return {1};

    vector<int> arr(k+1);
    arr[0] = 1;
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= i/2; ++j) {
            arr[j] += arr[j-1];
        }
        for(int j = i/2+1; j <= i; ++j)  arr[j] = arr[i-j];
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int k = 1; cin >> k;
    for(int &it: printKPascalTRow(k)) cout << it << " ";
    cout <<endl;
    return 0;
}