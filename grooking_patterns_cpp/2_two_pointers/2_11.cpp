#include <bits/stdc++.h>
using namespace std;

void swap(unsigned &a, unsigned &b){
    unsigned tmp = a;
    a = b; b = tmp;
}

void dutch_flag_sort(vector<unsigned> &array){
    size_t left = 0, i = 0, right = array.size()-1;
    while(i <= right){
        if(array[i] == 0) swap(array[i++],array[left++]);
        else if(array[i] == 2) swap(array[i],array[right--]);
        else i++;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    size_t n; unsigned tmp;
    vector<unsigned> array;
    
    cout << "Enter number of elements in the array: " << endl; cin >> n;
    cout << "Enter the array: " << endl;
    while(n--) cin >> tmp, array.push_back(tmp);

    dutch_flag_sort(array);
    printf("sorted: "); n = 0;
    while(n < array.size()) printf("%u ",array[n++]);
    printf("\n");
    return 0;
}