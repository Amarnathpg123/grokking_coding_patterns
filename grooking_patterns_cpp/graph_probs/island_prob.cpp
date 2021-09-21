#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &M, int i, int j) {
	if (i < 0 || j < 0 || i > (M.size() - 1) || j > (M[0].size() - 1) || M[i][j] != 1) return;

	if (M[i][j]) {
		M[i][j] = 0;

		DFS(M, i + 1, j);	 
		DFS(M, i - 1, j);	 
		DFS(M, i, j + 1);	 
		DFS(M, i, j - 1);	 
		DFS(M, i + 1, j + 1); 
		DFS(M, i - 1, j - 1); 
		DFS(M, i + 1, j - 1); 
		DFS(M, i - 1, j + 1); 
	}
}

int countIslands(vector<vector<int>> &M) {
	int ROW = M.size();
	int COL = M[0].size();
	int count = 0;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (M[i][j] == 1) {
				M[i][j] = 0;   //Manipulating input array for visited nodes
				count++;

				DFS(M, i + 1, j);	 
				DFS(M, i - 1, j);	 
				DFS(M, i, j + 1);	 
				DFS(M, i, j - 1);	 
				DFS(M, i + 1, j + 1); 
				DFS(M, i - 1, j - 1); 
				DFS(M, i + 1, j - 1); 
				DFS(M, i - 1, j + 1); 
            }
	return count;
}


int main()
{
	vector<vector<int>> M = {{1, 1, 0, 0, 0},
							{0, 1, 0, 0, 1},
							{1, 0, 0, 1, 1},
							{0, 0, 0, 0, 0},
							{1, 0, 1, 0, 1}};  //ans: 5

	cout << "Number of islands is: " << countIslands(M);
	return 0;
}


