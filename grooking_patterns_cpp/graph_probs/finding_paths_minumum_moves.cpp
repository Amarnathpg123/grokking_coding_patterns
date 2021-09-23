#include <bits/stdc++.h>
using namespace std;

//prevoius code is that it will calculate the minimum number of conversions from the initial to the final word. 
//Now, we need to fetch and display each new word after each conversion until we reach our end result. 
//We’ll traverse the list and return the complete sequence of words after each conversion from start to end.

void dfs(string w, string endWord, unordered_map<string, set<string>>&graph, vector<string>& path, vector<vector<string>>& ans){
    if(w == endWord){
        ans.push_back(path);
    }
    else{
        for(auto itr = graph[w].begin(); itr != graph[w].end(); ++itr){
            auto nw = *itr;
            path.push_back(nw);
            dfs(nw, endWord, graph, path, ans);
            path.pop_back();
        }      
    }
}

void possibleResults(string beginWord, string endWord, vector<string> wordList, vector<vector<string>>& res){
    if(beginWord == endWord){
        res.push_back({beginWord});
        return;
    }
    
    unordered_map<string, set<string>>graph;
    string helper = "qwertyuiopasdfghjklzxcvbnm";
    unordered_set<string>dicSet(wordList.begin(), wordList.end());
    
    unordered_set<string>layer;
    layer.insert(beginWord);
    dicSet.erase(beginWord);
    
    bool stop = false;
    while(layer.size() > 0 && !stop){
        unordered_set<string> newLayer;
        for(auto itr = layer.begin(); itr != layer.end(); ++itr){
            auto w = *itr;
            // construct next word, O(len(word) * 26)
            for(int i = 0; i < (int) w.length(); i++){
                for(auto c : helper){
                    auto nw = w.substr(0, i) + c + w.substr(i+1, w.length()-i-1);
                    
                    if(dicSet.find(nw) != dicSet.end()){
                        newLayer.insert(nw);
                        graph[w].insert(nw);
                        dicSet.erase(nw);
                    }   
                    // if we find endWord in this layer, there is no need to do next layer
                    if(nw == endWord)
                        stop = true;
                }
            }
        }
        // removing unecessary nodes
        // set<string> temp;
        // set_difference(dicSet.begin(), dicSet.end(), newLayer.begin(), newLayer.end(),
        //     inserter(temp, temp.end()));
        // dicSet = temp;
        layer = newLayer;
    }    
    
    vector<string> path = {beginWord};
    dfs(beginWord, endWord, graph, path, res);
}

void print(vector<vector<string>> &res) {
    for(auto &path: res) {
        for(auto &str: path) cout << str << " -> ";
        cout << "###" << endl;
    } 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    // Driver Code

    string initialWord = "hit";
    string finalWord = "cog";
    vector<string> wordGroup = {"hot","dot","dog","lot","log","cog","lit"};
    vector<vector<string>> res;
    possibleResults(initialWord, finalWord, wordGroup, res);
    cout << "All minimum sequences from " << initialWord << " -> " << finalWord << " are:\n";
    print(res);
    return 0;
}
