#include <bits/stdc++.h>
using namespace std;

long search_min_diff_element(vector<long> &arr, long const &k){
    long l = 0, r = arr.size()-1;
    if(k < arr[0]) return arr[0];
    if(k > arr[r]) return arr[r];

    while(l <= r){
        long mid = l + (r-l)/2;

        if(arr[mid] > k) r = mid-1;
        else if(arr[mid] < k) l = mid+1;
        else return arr[mid];
    }

    if(abs(arr[l]-k) < abs(arr[r]-k)) return arr[l];
    else return arr[r];
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
    
    printf("Element %ld is nearer to %ld\n", k, search_min_diff_element(arr, k));
    return 0;
}