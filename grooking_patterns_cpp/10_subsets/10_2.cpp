#include <bits/stdc++.h>
using namespace std;

void find_subsets_dups(vector<int> &array, vector<vector<int>> &res){
    sort(array.begin(), array.end());
    size_t start = 0, end = 0;
    for(size_t i = 0; i < array.size(); ++i){
        start = 0;
        if(i > 0 and array[i-1] == array[i])
            start = end+1;
        end = res.size()-1;
        for(size_t j = start; j <= end; ++j){
            vector<int> set = res[j];
            set.push_back(array[i]);
            res.push_back(set);
        }
    }
}

void print_subsets(vector<vector<int>> &res){
    for (size_t i = 0; i < res.size(); i++) {
		for (size_t j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> array = { 1, 1, 3, 3 };
	vector<vector<int>> res;

    res = {{}};
    find_subsets_dups(array, res);
    print_subsets(res);
    return 0;
}