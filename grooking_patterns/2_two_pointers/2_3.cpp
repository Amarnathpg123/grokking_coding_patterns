#include <bits/stdc++.h>
using namespace std;

vector<unsigned> squared_vec(vector<signed> &input_val){
    vector<unsigned> squared = {};
    squared.assign(input_val.size(), 0);

    size_t i = 0, j = input_val.size()-1, k = input_val.size()-1;
    unsigned left_square, right_square;

    while(i < j){
        left_square = input_val[i]*input_val[i], right_square = input_val[j]*input_val[j];
        if(left_square > right_square) squared[k] = left_square, i++, k--;
        else squared[k] = right_square, j--, k--;
    }
    return squared;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<signed> input_val;
    signed tp; size_t n;
    cout << "Enter the number of elements to be squared: " << endl;
    cin >> n;
    printf("Enter the sorted array...\n");

    while (n--) cin >> tp, input_val.push_back(tp);
    
    printf("Squared array: ");
    for(auto tp: squared_vec(input_val)) printf("%i ",tp); cout << endl;
    return 0;
}