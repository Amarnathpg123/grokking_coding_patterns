#include <bits/stdc++.h>
using namespace std;

class InfiniteArray{
    vector<long> arr;
public:
    void read(){
        long temp; cin >> temp;
        arr.push_back(temp);
    }

    long get_elem(long const &i){
        if(i >= arr.size()) return INT32_MAX;
        return arr[i];
    }
};

long inifinte_search(InfiniteArray &arr, long const &k){
    long start = 0, end = 1;
    while(arr.get_elem(end) < k){
        long temp = end+1;
        end = (end-start+1)*2;
        start = temp;
    }

    while(start <= end){
        long mid = start + (end - start)/2;

        if(arr.get_elem(mid) > k) end = mid-1;
        else if(arr.get_elem(mid) < k) start = mid+1;
        else return mid;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    long n, k; 
    cout << "Enter no. of elements: " << endl; cin >> n;
    cout << "Enter the key to be searched: " << endl; cin >> k;

    InfiniteArray arr;
    cout << "Enter the elements: " << endl;
    while(n) { arr.read(); n--; }
    
    printf("Element %ld is found at %ld\n", k, inifinte_search(arr, k));
    return 0;
}