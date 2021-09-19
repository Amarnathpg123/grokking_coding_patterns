#include <bits/stdc++.h>
using namespace std;

char binary_search_next_char(vector<char> &arr, char const &t){
    if(arr.size() == 1) return arr[0];

    size_t l = 0, r = arr.size()-1;
    if(arr[r] < t or arr[l] > t) return arr[l];
    while(l <= r){
        size_t mid = l + (r-l)/2;

        if(arr[mid] > t) r = mid-1;
        else if(arr[mid] < t) l = mid+1;
        else return arr[(mid+1)%arr.size()];
    }
    return arr[l%arr.size()];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unsigned n; 
    cout << "Enter no. characters: " << endl; cin >> n;
    vector<char> arr;
    char t;
    cout << "Enter the characters: " << endl;
    while(n){
        cin >> t; arr.push_back(t);
        n--;
    }
    cout << "Enter the char to be searched for upper bound: " << endl; cin >> t;

    cout <<  "Next letter of " << t << " is: " << binary_search_next_char(arr, t) << endl;
    return 0;
}