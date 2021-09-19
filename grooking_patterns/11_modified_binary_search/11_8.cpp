#include <bits/stdc++.h>
using namespace std;\

long bitonic_maximum_elem(vector<long> &arr){
    size_t l = 0, r = arr.size()-1;
    while(l < r){
        size_t mid = l + (r-l)/2;
        if(arr[mid] > arr[mid+1]) r = mid;
        else l = mid+1;
    }
    return l;
}

long binary_search(vector<long> &arr, long const &k, long l, long r){
    while(l <= r){
        long mid = l + (r-l)/2;

        if(arr[mid] == k) return mid;

        if(arr[l] < arr[r]){
            if(arr[mid] < k) l = mid+1;
            else r = mid-1;
        }
        else{
            if(arr[mid] < k) r = mid-1;
            else l = mid+1;
        }
    }
    return -1;
}

long bitonic_search_elem(vector<long> &arr, long const &k){
    long max = bitonic_maximum_elem(arr);
    long index = binary_search(arr, k, 0, max);
    if(index != -1) return index;
    index = binary_search(arr, k, max+1, arr.size()-1);
    return index;
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
    
    printf("Element %ld is found at %ld\n", k, bitonic_search_elem(arr, k));
    return 0;
}