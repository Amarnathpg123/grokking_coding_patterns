#include <bits/stdc++.h>
using namespace std;

long modified_binary_search(vector<long> &arr, long const &k){
    bool a2z = arr.front() < arr.back();
    long l = 0, r = arr.size()-1;
    while(l <= r){
        long mid = l + (r-l)/2;
        if(arr[mid] == k) return mid;

        if(a2z){
            if(arr[mid] > k) r = mid-1;
            else l = mid+1;
        }
        else{
            if(arr[mid] > k) l = mid+1;
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
    
    printf("Element %ld is found at %ld\n", k, modified_binary_search(arr, k));
    return 0;
}