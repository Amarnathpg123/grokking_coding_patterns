#include <bits/stdc++.h>
using namespace std;

int longest_no_repeat(string str){
    int win_start = 0, max_len = 0;
    unordered_map<char, int> umap;
    char t = 'a';
    while(t++ <= 'z') umap[t] = -1;
    for(int i = 0; i < str.length(); ++i){
        if(umap[str[i]] >= 0) win_start = max(win_start, umap[str[i]]+1);
        umap[str[i]] = i;
        max_len = max(max_len,i-win_start+1);
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    string str;
    cin >> str;
    auto start = std::chrono::high_resolution_clock::now();
    cout << longest_no_repeat(str);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
