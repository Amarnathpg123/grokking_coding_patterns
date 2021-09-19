#include <bits/stdc++.h>
using namespace std;

int longest_ones_sub_repl_k(vector<bool> vec, int k){
    int win_start = 0, max_len = 0, ones_cnt = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i]) ones_cnt++;
        if(i-win_start+1-ones_cnt > k) if(vec[win_start++]) ones_cnt--;
        max_len = max(max_len, i-win_start+1);
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int k;
    char t;
    vector<bool> vec;
    cin >> k;
    while(cin >> t, t != 'e') vec.push_back(int(t-'0'));
    auto start = std::chrono::high_resolution_clock::now();
    cout << longest_ones_sub_repl_k(vec, k);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
