#include <bits/stdc++.h>
using namespace std;

size_t count_rotations(vector<long> &arr){
    size_t l = 0, r = arr.size()-1;

    while(l <= r){
        size_t mid = l+ (r-l)/2;
        if(mid > l and arr[mid] > arr[mid+1]) return mid+1;
        if(mid < r and arr[mid-1] > arr[mid]) return mid;

        if(arr[mid] > arr[l]) l = mid+1;
        else r = mid-1; 
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long n, temp; 
    cout << "Enter no. of elements: " << endl; cin >> n;
    vector<long> arr;
    cout << "Enter the elements: " << endl;
    while(n--){ cin >> temp; arr.push_back(temp); }
    
    printf("Array was rotated %ld times arround the pivot\n", count_rotations(arr));
    return 0;
}