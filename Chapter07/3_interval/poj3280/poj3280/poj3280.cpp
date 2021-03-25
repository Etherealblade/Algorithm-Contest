/*
Description: 区间 DP

Keywords: 

ULR: page 138
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

int w[30], n, m, dp[2005][2005];
char s[2005], ch;

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef INTXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif
	
	int x, y;
	while (cin >> n >> m) {           //n是用到的字符个数，m是s的长度
		cin >> s;
		for (int i = 0; i < n; i++) {
			cin >> ch >> x >> y;         //读取每个字符的插入和删除的花费
			w[ch - 'a'] = min(x, y);   //取其中的最小值
		}
		for (int i = m - 1; i >= 0; i--)         //i是子区间的起点
			for (int j = i + 1; j < m; j++) {    //j是子区间的终点
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = min(dp[i + 1][j] + w[s[i] - 'a'],
						dp[i][j - 1] + w[s[j] - 'a']);
			}
		cout << dp[0][m - 1] << endl;
	}
	
	return 0;
}
