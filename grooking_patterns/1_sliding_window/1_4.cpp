#include <bits/stdc++.h>
using namespace std;

int longest_sub_2(vector<char> vec){
    int win_start = 0, max_len = 0, count = 0;
    unordered_map<char,int> umap;
    char t = 'A';
    while(t <= 'Z') umap[t++] = 0;
    for(int i = 0; i < vec.size(); ++i){
        t = vec[i];
        if(umap[t] == 0) count++;
        umap[t]++;
        while(count > 2){
            umap[vec[win_start]]--;
            if(!(umap[vec[win_start]])) count--;
            win_start++;
        }
        max_len = max(max_len, i-win_start+1);
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    char t;
    vector<char> vec;
    while(cin >> t, t != 'e') vec.push_back(t);
    auto start = std::chrono::high_resolution_clock::now();
    cout << longest_sub_2(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
