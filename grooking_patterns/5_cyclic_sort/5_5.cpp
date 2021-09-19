#include <bits/stdc++.h>
using namespace std;

void find_dups(vector<unsigned> &array, vector<unsigned> &dups){
    size_t i = 0, j = 0;
    dups = {};
    vector<int> int_array(array.begin(), array.end());
    while(i < int_array.size()){
        j = abs(int_array[i])-1;
        if(int_array[i] != int_array[j]) swap(int_array[i], int_array[j]);
        else i++;
    }

    for(i = 0; i < int_array.size(); ++i)
        if(int_array[i] != i+1) dups.push_back(int_array[i]);
}

void find_dups1(vector<unsigned> &array, vector<unsigned> &dups){
    size_t i = 0, j = 0;
    dups = {};
    vector<int> int_array(array.begin(), array.end());
    while(i < int_array.size()){
        j = abs(int_array[i++])-1;
        if(int_array[j] > 0) int_array[j] *= -1;
        else dups.push_back(j+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<unsigned> array;
    vector<unsigned> dups;
    size_t n;  unsigned temp;
    cout << "Enter the number of elements: " << endl; cin >> n;
    cout << "Enter the elements: "<< endl;
    while(n--){
        cin >> temp; array.push_back(temp);
    }

    printf("Repeating nums using negative values are: ");
    find_dups1(array, dups);
    for(unsigned &temp: dups) printf("%u ",temp);
    printf("\n");

    printf("Repeating nums using cyclic sort are: ");
    find_dups(array, dups);
    for(unsigned &temp: dups) printf("%u ",temp);
    printf("\n");
    return 0;
}