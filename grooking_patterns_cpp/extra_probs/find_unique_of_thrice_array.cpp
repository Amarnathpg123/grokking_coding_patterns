#include <bits/stdc++.h>
using namespace std;

int findSingle(vector<int> &arr) {
    int ones = 0, twos = 0;
    for(int i = 0; i < arr.size(); i++){
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }
    return ones;
}
 
//Bellow code works if 5 times and 3 times 
int findTrice(vector<int> &arr) {
    int ones = 0, twos = 0, threes = 0, fours = 0;
    for(int i = 0; i < arr.size(); ++i) {
        ones = (ones^arr[i]) & ~(twos) & ~(threes) & ~(fours);
        twos = (twos^arr[i]) & ~(ones) & ~(threes) & ~(fours);
        threes = (threes^arr[i]) & ~(twos) & ~(ones) & ~(fours);
        fours = (fours^arr[i]) & ~(twos) & ~(threes) & ~(ones);
    }
    return threes;
}

int singleNumber ( vector < int > &A) {

    int a = 0;
    int b = 0;

    for (int i = 0; i < A.size(); i++) {
        b |= a & A[i];
        a ^= A[i];
        int c = ~(a & b);
        a &= c;
        b &= c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {1,3,4,3,1,3,1,2,2};
    cout << "element which appears only once (all others thrice) is: " << findSingle(arr) << endl;
    return 0;
}