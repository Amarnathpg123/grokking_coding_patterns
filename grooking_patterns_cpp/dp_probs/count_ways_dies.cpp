#include<bits/stdc++.h>
using namespace std;

long findWays(int f, int d, int s)
{
    vector<vector<long>> mem(d+1, vector<long>(s+1, 0));
	mem[0][0] = 1;
	for (int i = 1; i <= d; i++)
	{
		for (int j = i; j <= s; j++)
		{
			// The result is obtained in two ways, pin the current dice and spending 1 of the value,
			// so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we
			// would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations
			// that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding
			// extra combinations, so we remove the combinations that only pin the extrapolated dice face and
			// subtract the extrapolated combinations.
			mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1];
			if (j - f - 1 >= 0)
				mem[i][j] -= mem[i - 1][j - f - 1];
		}
	}
	return mem[d][s];
}

int main(void)
{
	cout << findWays(4, 2, 1) << endl;
	cout << findWays(2, 2, 3) << endl;
	cout << findWays(6, 3, 8) << endl;
	cout << findWays(4, 2, 5) << endl;
	cout << findWays(4, 3, 5) << endl;
	return 0;
}

