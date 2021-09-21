#include <bits/stdc++.h>
#include <limits>
using namespace std;
using namespace std::chrono;

int smallest_sub_sum(int s, vector<int> vec){
    int win_start = 0, win_sum = 0, min_length = numeric_limits<int>::max();
    for(int i =0; i < vec.size(); ++i){
        win_sum += vec[i];
        while(win_sum >= s){
            min_length = min(min_length, i-win_start+1);
            win_sum -= vec[win_start++];
        }
    }
    return min_length;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    
    unsigned s;
    unsigned t;
    vector<int> vec;
    printf("please enter the positive numbers and end input line with -1\n");
    cin >> s;
    while(cin >> t, t != -1) vec.push_back(t);
    auto start = high_resolution_clock::now();
    cout << "Return value: " << smallest_sub_sum(s, vec) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
