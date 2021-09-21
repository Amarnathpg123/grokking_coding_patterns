#include <bits/stdc++.h>
using namespace std;

vector<int> find_word_concatenation(string &str, vector<string> &words)
{
    size_t word_count = words.size(), word_length = words[0].length();
    vector<int> indices;
    if(word_count == 0 || word_length == 0) return indices;

    unordered_map<string, size_t> umap, t;
    for(const auto &i: words) ++umap[i];

    for(size_t i = 0; i < (str.length()-word_count*word_length+1); ++i)
    {
        t.clear();
        for(size_t j = 0; j <= word_count; ++j)
        {
            string next_word = str.substr(i+j*word_length, word_length);
            if(umap.find(next_word) == umap.end()) break;

            ++t[next_word];

            if(t[next_word] > umap[next_word]) break;
            if(j+1 == word_count) indices.push_back(i);
        }
    }
    return indices;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    size_t t = 0;
    string str, temp;
    vector<string> words;

    cout << "Enter the strings starting with the main string" << endl;
    cin >> str;
    while (cin >> temp, temp != "-1") 
    {
        t += temp.length();
        words.push_back(temp);
    }
    assert(str.length() >= t);

    auto start = std::chrono::high_resolution_clock::now();
    for(int i: find_word_concatenation(str, words)) cout << i << " ";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "\nTime took: " << duration.count()/1000.0 << " ms \n";

    return 0;
}
