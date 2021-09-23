#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dict = {"GEEKS", "FOR", "QUIZ", "GO"};

bool isNeighbour(pair<int,int> &a, pair<int,int> &b) {
    return max(abs(a.first-b.first), abs(a.second-b.second)) < 2;
}

bool dfs(pair<int,int> curr, int idx, const string &str, unordered_map<char, vector<pair<int,int>>> &umap, vector<vector<bool>> &visited) {
    if(idx == str.length()-1) return 1;
    visited[curr.first][curr.second] = 1;
    for(auto &next: umap[str.at(idx+1)]) {
        if(not visited[next.first][next.second] and isNeighbour(curr, next))
            if(dfs(next, idx+1, str, umap, visited)) {
                visited[curr.first][curr.second] = 0;  // before returning make char not visited to use for other instances
                return 1;
            }
    }

    visited[curr.first][curr.second] = 0;
    return 0;
}

void findWords(vector<vector<char>> &boggle)  {
    unordered_map<char, vector<pair<int,int>>> umap;

    for(int i = 0; i < boggle.size(); ++i) {
        for(int j = 0; j < boggle[0].size(); ++j) {
            umap[boggle[i][j]].emplace_back(make_pair(i,j));
        }
    }

    vector<vector<bool>> visited(boggle.size(), vector<bool> (boggle[0].size(), 0));

    for(auto &str: dict) {
        for(auto &loc: umap[str.at(0)]) {
            if(dfs(loc, 0, str, umap, visited)) {
                printf("%s\n", str.c_str());
                break;
            }
        }
    }
            
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    // vector<vector<char>> boggle = { { 'G', 'I', 'Z' },
    //                       { 'U', 'E', 'K' },
    //                       { 'Q', 'S', 'E' } };

    vector<vector<char>> boggle = { {'G', 'E', 'Z'}, 
                                    {'E', 'O', 'I'},
                                    {'K', 'F', 'U'},
                                    {'S', 'Q', 'O'} };
    printf("Following words from dictionary are found in the boggle: \n");
    findWords(boggle);
    return 0;
}

//time complexity O(all characters in the all strings in the dictionary + m*n)
//space complexity O(m*n)