#include <bits/stdc++.h>
using namespace std;

unordered_set<string> uset = { "mobile", "samsung", "sam", "sung", "man",
			"mango", "icecream", "and", "go", "i",
			"like", "ice",	 "cream" };

inline bool dictionaryContains(string word){
	return uset.count(word);
}

bool wordBreak(string s){
	int n = s.size();
	if (n == 0)
		return true;

	vector<int> matched_index;
	matched_index.push_back(-1);

	for (int i = 0; i < n; i++) {
		int msize = matched_index.size(); 

		for (int j = msize - 1; j >= 0; j--) {
			string sb = s.substr(matched_index[j] + 1, i - matched_index[j]);

			if (dictionaryContains(sb)) {
				matched_index.push_back(i);
				break;
			}
		}
	}
	return matched_index.back()==(n-1);
}

int main(){
	wordBreak("ilikesamsung") ? cout << "Yes\n"
							: cout << "No\n";
	wordBreak("iiiiiiii") ? cout << "Yes\n"
						: cout << "No\n";
	wordBreak("") ? cout << "Yes\n" : cout << "No\n";
	wordBreak("ilikelikeimangoiii") ? cout << "Yes\n"
									: cout << "No\n";
	wordBreak("samsungandmango") ? cout << "Yes\n"
								: cout << "No\n";
	wordBreak("samsungandmangok") ? cout << "Yes\n"
								: cout << "No\n";
	return 0;
}