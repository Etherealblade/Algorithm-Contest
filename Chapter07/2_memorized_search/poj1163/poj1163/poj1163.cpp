/*
Description: 递归+记忆搜索

Keywords:

ULR: http://poj.org/problem?id=1163
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define INTXT

const int MAXX = 100;
int tri[MAXX][MAXX];
int dp[MAXX][MAXX];
int n;

int dfs(int i, int j)
{
	if (i == n)
	{
		return tri[i][j];
	}
	if (dp[i][j] >= 0)
	{
		return dp[i][j];
	}

	return dp[i][j] = max(dfs(i + 1, j), dfs(i + 1, j + 1)) + tri[i][j];
}

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef INTXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif

	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < i + 1; j++)
			cin >> tri[i][j];
	for (int i = 0; i < MAXX; i++)
		for (int j = 0; j < MAXX; j++)
			dp[i][j] = -1;

	cout << dfs(0, 0) << endl;

	return 0;
}