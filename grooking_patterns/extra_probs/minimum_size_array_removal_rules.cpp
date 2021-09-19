#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int ans = 0;
vector<vector<int>> dp(MAX, vector<int> (MAX, -1));

int recursion(vector<int> &arr, int low, int high, int const &k) {
	if(dp[low][high] != -1) return dp[low][high];
	if(high-low+1 < 3) return high-low+1;

	int res = 1 + recursion(arr, low+1, high, k);

	for(int i = low; i < high; ++i) {
		for(int j = i+1; j <= high; ++j) {
			if(arr[i] == arr[low]+k and arr[j] == arr[low]+2*k and 
				recursion(arr, low+1, i-1, k) == 0 and
				recursion(arr, i+1, j-1, k) == 0)
				res = min(res, recursion(arr, j+1, high, k));
		}
	}
	return dp[low][high] = res;
}

void minSizeArray(vector<int> &arr, int const &k) {
	ans = recursion(arr, 0, arr.size()-1, k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<int> arr = { 2, 4, 6, 8, 10, 12, 8, 10, 6, 8};
	int  k = 2;
	minSizeArray(arr, k);
	printf("Minimum size of the array after the removals: %d\n", ans);
	return 0;
}