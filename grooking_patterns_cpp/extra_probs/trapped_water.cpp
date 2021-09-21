#include <bits/stdc++.h>
using namespace std;

void trappedWater(vector<int> &arr, int &water) {
    int ml = arr[0], mr = arr.back(), l = 1, r = arr.size()-2;  //ml max left so far
    while(l <= r) {
        if(ml < mr) {
            if(ml < arr[l]) ml = arr[l];
            else water += ml-arr[l];
            l++;
        } else {
            if(mr < arr[r]) mr = arr[r];
            else water += mr-arr[r];
            r--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {4,2,0,6,2,3,5};
    int water = 0;
    trappedWater(arr, water);
    printf("Trapped water: %d\n", water);
    return 0;
}