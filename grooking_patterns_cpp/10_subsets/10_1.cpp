#include <bits/stdc++.h>
using namespace std;

void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
				vector<int>& subset, size_t index)
{
	res.push_back(subset);
	for (size_t i = index; i < A.size(); i++) {

		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		// backtracking.
		subset.pop_back();
	}

	return;
}

vector<vector<int> > subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int> > res;
	subsetsUtil(A, res, subset, 0);

	return res;
}

void find_subsets(vector<int> &A, vector<vector<int>> &res){
    for(int num: A){
        size_t n = res.size();
        for(size_t i = 0; i < n; ++i){
            vector<int> set = res[i];
            set.push_back(num);
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
    cin.tie(0), cout.tie(0);

    vector<int> array = { 1, 2, 3, 4 };
	vector<vector<int>> res = subsets(array);
    print_subsets(res);

    // res = {{}};
    // find_subsets(array, res);
    // print_subsets(res);
    return 0;
}