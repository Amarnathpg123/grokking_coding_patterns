#include <bits/stdc++.h>
using namespace std;

void sub_array_prod_lt_target(vector<unsigned> &array, vector<vector<unsigned>> &sub_arrays, unsigned const &target){
    unsigned prod = 1;
    int left = 0;
    for(int right = 0; right < array.size(); ++right){
        prod = prod * array[right];
        while(prod >= target and left < array.size()) {
            prod = prod / array[left++];
        }
        deque<unsigned> temp_list;
        for(int i = right; (i >= left && right >= left);--i){
            temp_list.push_front(array[i]); 
            sub_arrays.push_back({temp_list.begin(), temp_list.end()});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<unsigned> array;
    vector<vector<unsigned>> sub_arrays;
    unsigned target,n, tmp;

    cout << "Enter the target for the sub-arrays: " << endl; cin >> target;
    cout << "Enter the number of elements in the array: "<< endl; cin >> n;
    cout << "Enter the array: " << endl;
    while (n--) cin >> tmp, array.push_back(tmp);
    
    sub_array_prod_lt_target(array, sub_arrays, target);
    printf("Sub arrays with product lt target: ");
    for(auto &tmp: sub_arrays) { printf("[ "); for(auto &n: tmp) printf("%u ",n); printf("] "); }
    cout << endl;
    return 0;
}