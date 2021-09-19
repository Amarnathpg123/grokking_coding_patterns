#include <bits/stdc++.h>
using namespace std;

bool perm_pattern_str(string str, string pattern){
    int win_start = 0, cnt1 = 0, cnt2 = 0;
    unordered_map<char, int> umap;
    char t = 'a';
    while(t <= 'z') umap[t++]= -1;

    for(int i = 0; i < pattern.length(); ++i)
        if(umap[pattern[i]]++ == -1) umap[pattern[i]]++, cnt1++;

    for(int i = 0; i < str.length(); ++i){
        if(umap[str[i]] >= 0)
            if(--umap[str[i]] == 0) cnt2++;

        if(cnt1 == cnt2) return true;

        if(i >= pattern.length()-1)
            if(umap[str[win_start++]] >= 0)
                if(umap[str[win_start-1]]++ == 0) cnt2--;
    }
    return false;
}

std::vector<int> findAnagrams(std::string& s, std::string& t) {
    int xr = 0;
    for(auto &c: t) xr ^= c;
    std::vector<int> output;

    for(int i = 0; i < s.length(); ++i) {
        xr ^= s[i];
        if(xr == 0) output.emplace_back(i-t.length()+1);
        if(i >= t.length()-1)  xr ^= s[i-t.length()+1];
    }

    return output;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    string str, pattern;
    cin >> str >> pattern;
    assert(str.length() >= pattern.length());
    auto start = std::chrono::high_resolution_clock::now();
    if(perm_pattern_str(str, pattern)) cout << "True";
    else cout << "False";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";
    
    return 0;
}
