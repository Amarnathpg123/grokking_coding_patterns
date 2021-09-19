#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> triplet;

triplet make_triple(int &a, int &b, int &c){
    return make_pair(a,make_pair(b,c));
}

void triple_sum_to_null(vector<int> &array, vector<triplet> &trip){
    if(array.size() < 3) {cout << "triplets cann't be formed with < 3 elements\n"; return;}
    if(array.size() == 3) {
        if((array[0]+array[1]+array[2]) == 0) 
            trip = {make_triple(array[0], array[1], array[2])};
        return;
    }
    sort(array.begin(), array.end());
    for(size_t i = 0; i < array.size(); ++i){
        if(array[i-1] == array[i]) continue;
        size_t left = i + 1, right = array.size()-1;
        while (left < right)
        {
            while(left < right and array[left-1] == array[left]) left++;
            while(left < right and array[right] == array[right+1]) right--;
            int sum = array[left] + array[right];
            if(sum == -array[i]) trip.push_back(make_triple(array[i],array[left],array[right]));
            if(-array[i] > sum) left++;
            else right--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    size_t n; int tmp;
    vector<int> array = {};
    vector<triplet> trip = {};
    cout << "Enter the number of elemnts: " << endl;
    cin >> n;
    cout << "Enter the array elements: " << endl;
    while(n--) cin >> tmp, array.push_back(tmp);

    triple_sum_to_null(array, trip);
    if(trip.size()) {
        printf("triplets are:\n ");
        for(triplet &i: trip) printf("(%d, %d, %d)\n",i.first, i.second.first, i.second.second);
    }
    else printf("No triplets found!\n");
    return 0;
}
