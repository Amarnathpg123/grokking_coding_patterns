#include <bits/stdc++.h>
using namespace std;

void pair_with_targetsum(vector<int> &numbers, int &target)
{
    auto i = numbers.begin(), j = numbers.end()-1;
    while(i<j){
        if((*i + *j) < target) ++i;
        else if((*i + *j) > target) --j;
        else { cout << int(i-numbers.begin()) << " " << int(j-numbers.begin()) << endl; return;}
    }
    cout << "-1 -1\n";
}

int main()
{   
    int target, t;
    vector<int> numbers;
    cout << "Enter target" << endl;
    cin >> target;
    cout << "Enter the sorted numbers" << endl;
    while(cin >> t, t != -1) numbers.push_back(t);

    auto start = std::chrono::high_resolution_clock::now();
    pair_with_targetsum(numbers, target);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}