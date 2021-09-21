#include <bits/stdc++.h>
using namespace std;

void remove_duplicates(vector<int> &numbers)
{
    std::vector<int>::iterator i = numbers.begin()+1, j = numbers.begin()+1;
    while(i < numbers.end()) {
        if(*(j-1) != *i) *j = *i, ++j; ++i;
    }
    cout << (j-numbers.begin());
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    vector<int> numbers;
    int t;
    cout << "Enter the sorted array" << endl;
    while(cin >> t, t != -1) numbers.push_back(t);
    
    auto start = std::chrono::high_resolution_clock::now();
    remove_duplicates(numbers);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";
    return 0;
}