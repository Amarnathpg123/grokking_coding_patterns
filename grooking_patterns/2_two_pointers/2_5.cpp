#include <bits/stdc++.h>
using namespace std;

int closset_triplet_sum(vector<int> &array, int const &target){
    if(array.size() < 3) {cerr << "triplets cann't be formed with < 3 elements\n"; exit(1);}
    if(array.size() == 3) return array[0]+array[1]+array[2];

    sort(array.begin(), array.end());
    int small_diff = INT32_MAX, target_diff;
    for(size_t i = 0; i < array.size(); ++i){
        size_t left = i + 1, right = array.size()-1;
        while(left < right){
            target_diff = target - array[i] - array[left] - array[right];
            if(target_diff == 0) return target-target_diff;

            if(abs(target_diff) < abs(small_diff) or (abs(target_diff) == abs(small_diff) and target_diff > small_diff))
                small_diff = target_diff;
            
            if(target_diff > 0) left++;
            else right--;
        }
    }
    return target-small_diff;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    size_t n; int tmp, target;
    vector<int> array = {};
    cout << "Enter the target sum for triplets: " << endl;
    cin >> target;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    cout << "Enter the array elements: " << endl;
    while(n--) cin >> tmp, array.push_back(tmp);

    cout << "clossest target sum: " << closset_triplet_sum(array, target) << endl;
    return 0;
}