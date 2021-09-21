#include <bits/stdc++.h>
using namespace std;

pair<long, long> find_2unique(vector<long> arr){
    if(arr.size() < 2) return make_pair(-1,-1);

    long n1 = 0, n2 = 0, n1xn2 = 0;
    for(long &num: arr) n1xn2 ^= num;

    //right most set bit of n1xn2
    long set_bit = n1xn2 & ~(n1xn2-1);  // or x^(x&(x-1))

    for(long &num: arr){
        if(set_bit & num) n1 ^= num;
        else n2 ^= num;
    }
    return make_pair(n2,n1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n;
    cout << "Enter no. elements: " << endl; cin >> n;
    long temp;
    vector<long> arr;
    cout << "Enter the elemets: " << endl;
    while(n){
        cin >> temp; arr.push_back(temp);
        n--;
    }
    
    pair<long, long> temp1 = find_2unique(arr);
    printf("Two unique numbers are: %ld %ld\n", temp1.first, temp1.second);
    return 0;
}