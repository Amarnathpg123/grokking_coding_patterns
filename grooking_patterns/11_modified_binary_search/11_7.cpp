#include <bits/stdc++.h>
using namespace std;

long bitonic_maximum_elem(vector<long> &arr){
    size_t l = 0, r = arr.size()-1;
    while(l < r){
        size_t mid = l + (r-l)/2;
        if(arr[mid] > arr[mid+1]) r = mid;
        else l = mid+1;
    }
    return arr[l];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n, temp; 
    cout << "Enter no. of elements: " << endl; cin >> n;
    vector<long> arr;
    cout << "Enter the elements: " << endl;
    while(n){ cin >> temp; arr.push_back(temp); n--; }

    printf("Maximum element of the bitonic array is: %ld\n", bitonic_maximum_elem(arr));
    return 0;
}