#include <bits/stdc++.h>
using namespace std;

int max_sub_k(vector<int> vec, int k){
    int win_start = 0, win_sum = 0, max_sum = 0;
    for(int i = 0; i < vec.size(); ++i){
        win_sum += vec[i];
        if(i >= k-1){
            max_sum = max(max_sum, win_sum);
            win_sum -= vec[win_start++];
        }
    }
    return max_sum;
}

int main(){
    ios_base::sync_with_stdio(0);   
    cout.tie(0), cin.tie(0);

    unsigned k;
    unsigned t;
    printf("please enter the positive numbers and end input line with -1\n");
    cin >> k;
    assert(k>0);
    vector<int> vec;
    while(cin >> t, t != -1) vec.push_back(t);
    try {
        if(vec.size() < k) throw k;
        else {
            auto start = std::chrono::high_resolution_clock::now();
            cout << max_sub_k(vec, k) << '\n';
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << "Time took: " << duration.count()/1000.0 << " ms \n";
            }
    }
    catch (...){
        cout << "Ensure the vector size greater than k\n";
    }

    return 0;
}
