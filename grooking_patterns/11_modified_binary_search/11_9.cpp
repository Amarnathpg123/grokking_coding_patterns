#include <bits/stdc++.h>
using namespace std;

long rotated_search_elem(vector<long > &arr, long &k){
    long l = 0, r = arr.size()-1;

    while(l <= r){
        long mid = l + (r-l)/2;

        if(arr[mid] == k) return mid;

        if(arr[l] <= arr[mid]){
            if(arr[mid] > k and k > arr[l]) r = mid-1;
            else l = mid+1;
        }
        else{
            if(arr[mid] < k and arr[r] > k) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}

long rotated_search_elem_dups(vector<long > &arr, long &k){
    long l = 0, r = arr.size()-1;

    while(l <= r){
        long mid = l + (r-l)/2;

        if(arr[mid] == k) return mid;

        if(arr[l] == arr[mid] and arr[mid] == arr[r]) l++, r--;
        else if(arr[l] <= arr[mid]){
            if(arr[mid] > k and k > arr[l]) r = mid-1;
            else l = mid+1;
        }
        else{
            if(arr[mid] < k and arr[r] > k) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
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
    
    printf("Element %ld is found at %ld\n", k, rotated_search_elem(arr, k));
    printf("Element %ld is found at %ld\n", k, rotated_search_elem_dups(arr, k));
    return 0;
}

// 3 7 3 3 3    search for 7