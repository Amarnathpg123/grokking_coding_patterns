#include <bits/stdc++.h>
using namespace std;

string smallest_window_substring(string str, string pattern){
    int win_start = 0, cnt = 0, sub_start = 0, min_length = str.length()+1, dflt = -min_length;
    unordered_map<char, int> umap;
    char t = 'a';
    while(t <= 'z') umap[t++] = dflt;

    for(int i = 0; i < pattern.length(); ++i){
        if(umap[pattern[i]] == dflt) umap[pattern[i]] = 1;
        else umap[pattern[i]]++;
    }

    for(int i = 0; i < str.length(); ++i){
        if(umap[str[i]] != dflt){
            umap[str[i]]--;
            if(umap[str[i]] >= 0) cnt++;
        }

        while(cnt == pattern.length()){
            if(min_length > i - win_start + 1) min_length = i - win_start + 1, sub_start = win_start;
            if(umap[str[win_start++]] != dflt){
                if(umap[str[win_start-1]] == 0) cnt--;
                umap[str[win_start-1]]++; 
            }
        }
    }
    if(min_length > str.length()) return "";
    return str.substr(sub_start, min_length);
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    string str, pattern;
    cin >> str >> pattern;
    assert(str.length() >= pattern.length());
    string temp = smallest_window_substring(str, pattern);
    cout << temp;
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
