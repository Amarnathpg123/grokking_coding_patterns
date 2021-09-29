#include <bits/stdc++.h>
using namespace std;

int findMaxrectangle(vector<int> &arr) {
    if(arr.size() == 1) return arr[0];
    stack<int> sk;

    int i = 0, n = arr.size(), mx_area = 0;
    vector<int> left(n, 0), right(n, 0);
    while(i < n) {
        if(sk.empty()) left[i] = 0;
        else if(arr[sk.top()] < arr[i]) left[i] = i;
        else {
            while(not sk.empty() and arr[sk.top()] >= arr[i]) sk.pop();
            if(sk.empty()) left[i] = 0;
            else left[i] = sk.top()+1;
        }
        sk.push(i++);
    }

    i = n-1;
    while(not sk.empty()) sk.pop(); 
    while(i >= 0) {
        if(sk.empty()) right[i] = n-1;
        else if(arr[sk.top()] < arr[i]) right[i] = i;
        else {
            while(not sk.empty() and arr[sk.top()] >= arr[i]) sk.pop();
            if(sk.empty()) right[i] = n-1;
            else right[i] = sk.top()-1;
        }
        sk.push(i--);
    }

    i = 0;
    while(i < n)
        mx_area = max(mx_area, (right[i]-left[i]+1)*arr[i++]); 

    return mx_area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << "Maximum rectangular area in the given hist: " << findMaxrectangle(arr) << endl;
    return 0;
}