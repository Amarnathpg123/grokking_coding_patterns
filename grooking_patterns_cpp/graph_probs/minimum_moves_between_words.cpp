#include <bits/stdc++.h>
using namespace std;

//We’ll be provided with an initial word, a final word, and a word group in the form of a list. 
//Our code needs to pick the shortest sequence of words of the same length from the word group, 
//starting with the initial word and ending at the final word. 
//This sequence should be such that each consecutive word differs from the previous one in one letter only.

int minimumMoves(std::string beginWord, std::string endWord, std::vector<std::string> wordList) {

    // Since all words are of same length.
    int L = beginWord.length();

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    std::unordered_map<std::string, std::vector<std::string>> allComboDict;

    for(auto word : wordList) {
      for (int i = 0; i < L; i++) {
        // Key is the generic word
        // Value is a list of words which have the same intermediate generic word.
        std::string newWord = word.substr(0, i) + '*' + word.substr(i + 1, (L - i - 1));
        std::vector<std::string> transformations;
        if(allComboDict.find(newWord) != allComboDict.end()){
            transformations = allComboDict[newWord];
        }  
        transformations.push_back(word);
        allComboDict[newWord] = transformations;
      }
    }

    // Queue for BFS
    std::queue<std::pair<std::string, int>> Q;
    Q.push({beginWord, 0});

    // Visited to make sure we don't repeat processing same word.
    std::unordered_map<std::string, bool> visited;
    visited[beginWord] = true;

    while (!Q.empty()) {
      std::pair<std::string, int> node = Q.front();
      Q.pop();
      std::string word = node.first;
      int level = node.second;
      for (int i = 0; i < L; i++) {

        // Intermediate words for current word
        std::string newWord = word.substr(0, i) + '*' + word.substr(i + 1, (L - i - 1));

        // Next states are all the words which share the same intermediate state.
        std::vector<std::string> temp;
        if(allComboDict.find(newWord) != allComboDict.end()){
            temp = allComboDict[newWord];
        }
        for (std::string adjacentWord : temp) {
          // If at any point if we find what we are looking for
          // i.e. the end word - we can return with the answer.
          if (adjacentWord == endWord) {
              return level + 1;
          }
          // Otherwise, add it to the BFS Queue. Also mark it visited
          if (visited.find(adjacentWord) == visited.end()) {
              visited[adjacentWord] = true;
              Q.push({adjacentWord, level + 1});
          }
        }
      }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    // Driver code

    std::string initialWord = "hit";
    std::string finalWord = "cog";
    std::vector<std::string> wordGroup = {"hot","dot","dog","lot","log","cog"};

    std::cout << "The shortest sequece is of length: " << minimumMoves(initialWord, finalWord, wordGroup);
    return 0;
}