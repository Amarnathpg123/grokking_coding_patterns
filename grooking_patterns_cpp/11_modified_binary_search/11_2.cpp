#include <bits/stdc++.h>
using namespace std;

long modified_binary_search_ceil(vector<long> &arr, long const &k){
    long l = 0, r = arr.size()-1;
    if(arr[r] < k) return -1;
    while(l <= r){
        long mid = l + (r-l)/2;

        if(arr[mid] == k) return arr[mid];
        else if(arr[mid] > k) r = mid-1;
        else l = mid+1;
    }
    return arr[l];   
}

long modified_binary_search_floor(vector<long> &arr, long const &k){
    long l = 0, r = arr.size()-1;
    if(arr[l] > k) return -1;
    while(l <= r){
        long mid = l + (r-l)/2;
        
        if(arr[mid] == k) return arr[mid];
        else if(arr[mid] > k) r = mid-1;
        else l = mid+1;
    }
    return arr[r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long n; 
    cout << "Enter no. of elements: " << endl; cin >> n;
    vector<long> arr; long temp, k;
    cout << "Enter the key to be searched: " << endl; cin >> k;
    cout << "Enter the elements: " << endl;
    while(n--){ cin >> temp; arr.push_back(temp); }
    
    printf("Ceil of element %ld is %ld\n", k, modified_binary_search_ceil(arr, k));
    printf("Floor of element %ld is %ld\n", k, modified_binary_search_floor(arr, k));
    return 0;
}