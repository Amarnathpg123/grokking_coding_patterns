#include <bits/stdc++.h>
using namespace std;

vector<int> findSpiral(vector<vector<int>> &arr) {
    int i = 0, l = 0, r = arr[0].size()-1, t = 0, b = arr.size()-1;
    int dir = 0;

    vector<int> ans;

    while(t <= b and l <= r) {
        if(dir == 0) {
            for(i = l; i <= r; ++i) ans.emplace_back(arr[t][i]);
            t++;
        } else if(dir == 1) {
            for(i = t; i <= b; ++i) ans.emplace_back(arr[i][r]);
            r--;
        } else if(dir == 2) {
            for(i = r; i>=l; --i) ans.emplace_back(arr[b][i]);
            b--;
        } else {
            for(i = b; i >= t; --i) ans.emplace_back(arr[i][l]);
            l++;
        }
        dir = (dir+1)%4;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << "Spiral of the 2D array is: ";
    for(auto &it: findSpiral(arr)) cout << it << " ";

    cout << endl;
    return 0;
}