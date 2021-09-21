#include <bits/stdc++.h>
using namespace std;

vector<int> perm_pattern_str_ind(string str, string pattern){
    int win_start = 0, cnt1 = 0, cnt2 = 0;
    vector<int> indices;
    unordered_map<char, int> umap;

    for(int i = 0; i < pattern.length(); ++i) umap[pattern[i]]++;
    cnt1 = umap.size();

    for(int i = 0; i < str.length(); ++i){ 
        if(umap.find(str[i]) != umap.end())
            if(--umap[str[i]] == 0) cnt2++;

        if(cnt1 == cnt2) indices.push_back(win_start);

        if(i >= pattern.length()-1)
            if(umap.find(str[win_start++]) != umap.end())
                if(umap[str[win_start-1]]++ == 0) cnt2--;
    }
    return indices;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    string str, pattern;
    cin >> str >> pattern;
    assert(str.length() >= pattern.length());

    auto start = std::chrono::high_resolution_clock::now();
    for(int i : perm_pattern_str_ind(str, pattern)) cout << i << " ";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
