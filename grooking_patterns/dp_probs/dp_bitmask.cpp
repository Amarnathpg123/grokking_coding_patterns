//Maximum subset sum such that no 
//two elements in set have same digit in them
#include <bits/stdc++.h>
using namespace std;
int dp[1024];

int get_binary(int u)
{
	int ans = 0;
	while (u) {
		int rem = u % 10;
		ans |= (1 << rem);
		u /= 10;
	}

	return ans;
}

int recur(int u, int array[], int n)
{
	if (u == 0)
		return 0;
	if (dp[u] != -1)
		return dp[u];

	for (int i = 0; i < n; i++) {
		int mask = get_binary(array[i]);

		if ((mask | u) == u) {
			dp[u] = max(max(0,
					dp[u ^ mask]) + array[i], dp[u]);
		}
	}

	return dp[u];
}

int solve(int array[], int n)
{
	for (int i = 0; i < (1 << 10); i++) {
		dp[i] = -1;
	}

	int ans = 0;

	for (int i = 0; i < (1 << 10); i++) {
		ans = max(ans, recur(i, array, n));
	}

	return ans;
}

int main()
{
	int array[] = { 22, 132, 4, 45, 12, 223 };
	int n = sizeof(array) / sizeof(array[0]);
	
	cout << solve(array, n);
}
