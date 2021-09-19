#include <bits/stdc++.h>
using namespace std;

int find_dup(vector<unsigned> &array){
    size_t i = 0, j = 0;
    while(i < array.size()){
        if(array[i] != i+1){
            j = array[i]-1;
            if(array[i] != array[j]) swap(array[i], array[j]);
            else return array[i];
        }
        else i++;
    }
    return -1;
}

int find_dup1(vector<unsigned> &array){
    size_t i = 0, j = 0;
    vector<int> int_array(array.begin(), array.end());
    while(i < int_array.size()){
        j = abs(int_array[i++]) - 1;
        if(int_array[j] > 0) int_array[j] *= -1;
        else return j+1;
    }
    return -1;
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

    printf("Repeating num is: %d\n", find_dup1(array));

    printf("Repeating num is: %d\n", find_dup(array));
    return 0;
}