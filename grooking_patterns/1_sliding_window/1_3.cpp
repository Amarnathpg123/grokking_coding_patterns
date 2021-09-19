#include <bits/stdc++.h>
using namespace std;

int longest_sub_k(string str, int k){
    int win_start = 0, max_len = 0, count = 0;
    unordered_map<char,int> umap;
    char t = 'a';
    while(t <= 'z') umap[t++] = 0;
    for(int i = 0; i < str.length(); ++i){
        t = str[i];
        if(umap[t] == 0) count++;
        umap[t]++;
        while(count > k){
            umap[str[win_start]]--;
            if(!(umap[str[win_start]])) count--;
            win_start++;
        }
        max_len = max(max_len, i-win_start+1);
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

      int k;
    string str;
    cin >> k >> str;
    auto start = std::chrono::high_resolution_clock::now();
    cout << longest_sub_k(str, k);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
