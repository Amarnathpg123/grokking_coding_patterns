#include <bits/stdc++.h>
using namespace std;

void flip_invert_matrix(vector<vector<bool>> &arr){
    size_t n = arr[0].size();
    for(size_t i = 0; i < arr.size(); ++i){
        for(size_t j = 0; j < (n+1)/2; ++j){
            arr[i][j] = !arr[i][j];
            if(j < n-j-1) arr[i][n-j-1] = !arr[i][n-j-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t m,n;
    bool t;
    cout << "Enter the no. rows and columns: " << endl; 
    cin >> m >> n;
    vector<vector<bool>> arr(m, vector<bool>(n,false));
    cout << "Enter the matrix(rowwise): " << endl;
    for(size_t i = 0; i < m; ++i){
        for(long j = n-1; j >= 0; --j){
            cin >> t; arr[i][j] = t;
        }
    }

    flip_invert_matrix(arr);

    for(size_t i = 0; i < m; ++i){
        for(size_t j = 0; j < n; ++j) cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}