#include <bits/stdc++.h>
using namespace std;

long binary_search_range(vector<long> &arr, long const &k, bool b){
    long ki = -1, l = 0, r = arr.size()-1;
    while(l <= r){
        long mid = l + (r-l)/2;
        
        if(arr[mid] > k) r = mid-1;
        else if(arr[mid] < k) l = mid+1;
        else{
            ki = mid;
            if(b) l = mid+1;
            else r = mid-1;
        }
    }
    return ki;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long n, temp, k; 
    cout << "Enter number of elements and key to find: " << endl; cin >> n >> k;
    vector<long> arr;
    cout << "Enter the elements: " << endl;
    while(n--){ cin >> temp; arr.push_back(temp); }
    long lower = -1, upper = -1;
    lower = binary_search_range(arr, k, false);
    if(lower >= 0) upper = binary_search_range(arr, k, true);

    printf("Key %ld search range is: %ld %ld\n", k ,lower , upper);
    return 0;
}