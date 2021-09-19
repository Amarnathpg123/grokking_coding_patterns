#include <bits/stdc++.h>
using namespace std;

void find_permutations(vector<int> &array, size_t index, vector<int> current_perm, vector<vector<int>> &res){
    if(index == array.size()) 
        res.push_back(current_perm);
    else{
        for(size_t i = 0; i <= current_perm.size(); ++i){
            vector<int> new_perm(current_perm.begin(), current_perm.end());
            new_perm.insert(new_perm.begin()+i, array[index]);
            find_permutations(array, index+1, new_perm, res);
        }
    }
}

void print_perms(vector<vector<int>> &res){
    for (size_t i = 0; i < res.size(); i++) {
		for (size_t j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> array = { 1, 3, 5 };
	vector<vector<int>> res;

    find_permutations(array, 0, {}, res);
    print_perms(res);
    return 0;
}