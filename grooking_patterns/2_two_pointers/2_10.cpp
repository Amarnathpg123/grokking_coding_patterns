#include <bits/stdc++.h>
using namespace std;

unsigned smallest_sub_array_unsorted(vector<int> &array){
    size_t left = 0, right = array.size()-1;
    while(left < array.size() and array[left] < array[left+1]) left++;
    if(left == array.size()-1) return 0;
    while(right > 0 and array[right-1] < array[right]) right--;
    
    int maxe = INT16_MIN;
    int mine = INT16_MAX;
    for(size_t k = left; k <= right; ++k) {
        maxe = max(maxe, array[k]); 
        mine = min(mine, array[k]);
    }

    while(left > 0 and array[left-1] > mine) left--;
    while(right < array.size()-1 and array[right+1] < maxe) right++;

    return right-left+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<int> array;
    int n, tmp;
    cout << "Enter number of elements in the array: " << endl; cin >> n;
    cout << "Enter the array: " << endl;
    while(n--) {cin >> tmp; array.push_back(tmp);}

    cout << "length of sub array need to be sorted for whole array to be sorted: " << smallest_sub_array_unsorted(array) << endl;
    return 0;
}