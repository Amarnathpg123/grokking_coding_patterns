#include <bits/stdc++.h>
using namespace std;

void cyclic_sort(vector<unsigned> &array){
    size_t i = 0, j = 0;
    while(i < array.size()){
        j = array[i];
        if(array[i] != array[j]) swap(array[i], array[j]);
        else i++;
    }
}

unsigned missing_num(vector<unsigned> &array){
    return array.size()*(array.size()+1)/2 - accumulate(array.begin(), array.end(), 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<unsigned> array;
    size_t n;  unsigned temp;
    cout << "Enter the number of elements: " << endl; cin >> n;
    cout << "Enter the elements: "<< endl;
    while(n--){
        cin >> temp; array.push_back(temp);
    }

    printf("Missing number using sum is: %u\n", missing_num(array));

    cyclic_sort(array);

    for(size_t n = 0; n < array.size(); ++n){
        if(array[n] != n){
            printf("Missing number using cyclic sort is: %lu\n", n);
            break;
        }
    }
    return 0;
    
}