#include <bits/stdc++.h>
using namespace std;

size_t longest_path_cell(vector<vector<long>> &matrix, vector<vector<size_t>> &dp, size_t i, size_t j){
    if(i == 0 or i > matrix.size() or j == 0 or j > matrix[0].size())
        return 0;

    if(dp[i][j]) return dp[i][j];

    size_t t = 1;

    if(j < matrix[0].size() and matrix[i-1][j-1]+1 == matrix[i-1][j])
        t = max(t, 1 + longest_path_cell(matrix, dp, i, j+1));

    if(j > 1 and matrix[i-1][j-1]+1 == matrix[i-1][j-2])
        t = max(t, 1 + longest_path_cell(matrix, dp, i, j-1));
    
    if(i < matrix.size() and matrix[i-1][j-1]+1 == matrix[i][j-1])
        t = max(t, 1 + longest_path_cell(matrix, dp, i+1, j));

    if(i > 1 and matrix[i-1][j-1]+1 == matrix[i-2][j-1])
        t = max(t, 1 + longest_path_cell(matrix, dp, i-1, j));

    dp[i][j] = t; return dp[i][j];
}

void longest_increasing_path(vector<vector<long>> &matrix){
    size_t res = 1;

    vector<vector<size_t>> dp(matrix.size()+1, vector<size_t> (matrix[0].size()+1, 0));

    for(size_t i = 1; i <= matrix.size(); ++i){
        for(size_t j = 1; j <= matrix[0].size(); ++j){
            if(not dp[i][j]) dp[i][j] = longest_path_cell(matrix, dp, i, j);
            res = max(res, dp[i][j]);
        }
    }
    printf("Length of longest increasing (by exactly 1 unit) path in the matrix is: %lld\n", res);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t m, n; cin >> m >> n;
    vector<vector<long>> matrix(m, vector<long> (n,-1));
    for(size_t i = 0; i < m; ++i){
        for(size_t j = 0; j < n; ++j)
            cin >> matrix[i][j];
    }

    longest_increasing_path(matrix);
    return 0;
}