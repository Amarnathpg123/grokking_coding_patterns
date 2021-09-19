#include <bits/stdc++.h>
using namespace std;

unsigned count_triplets_lt_target(vector<int> &array, int const &target){
    if(array.size() < 3) {cerr << "triplets cann't be formed with < 3 elements\n"; exit(1);}
    if(array.size() == 3) if(array[0]+array[1]+array[2] < target) return 1;

    sort(array.begin(), array.end());
    unsigned count = 0;
    for(size_t i = 0; i < array.size()-1; ++i){
        size_t left = i+1, right = array.size()-1;
        while(left < right){
            if(array[i]+array[left]+array[right] < target) count += right - left++;
            else right--;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<int> array;
    int target, tmp; size_t n;
    cout << "Enter the target for the triplet: " << endl; cin >> target;
    cout << "Enter the number of elements in the array: " << endl; cin >> n;
    cout << "Enter the array: " << endl;
    while(n--)
        cin >> tmp, array.push_back(tmp);

    cout << "Count of triplets which sum lt target: " << count_triplets_lt_target(array, target) << endl;
    return 0;
}