/*
Description: 状态压缩dp, 经典题

Keywords:

ULR:
https://programmer.group/poj-1185-artillery-position.html
https://www.programmersought.com/article/13332558299/
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define INTXT

int n, m, vaild[65], cn[65], cnt;
int place[105];
char s[15];
int dp[105][65][65];
void judge()
{
	int p, num;
	cnt = 0;
	for (int i = 0; i < 1 << 10; i++)
	{
		if (((i << 1)&i) || ((i << 2)&i))
		{
			continue;
		}
		int temp = i;
		while (temp)
		{
			if (temp % 2)cn[cnt]++;
			temp >>= 1;
		}
		vaild[cnt++] = i;
	}
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

	judge();
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
			place[i] = 0;
			for (int j = 0; j < m; j++)
			{
				place[i] <<= 1;
				if (s[j] == 'H')
				{
					place[i]++;
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				for (int j = 0; vaild[j] < 1 << m && j < cnt; j++)
				{
					if ((place[1] & vaild[j]) == 0)
					{
						dp[1][j][0] = cn[j];
					}
					ans = max(ans, dp[1][j][0]);
				}
			}
			else if (i == 2)
			{
				for (int j = 0; vaild[j] < 1 << m && j < cnt; j++)
				{
					if ((place[2] & vaild[j]) == 0)
					{
						for (int k = 0; vaild[k] < 1 << m && k < cnt; k++)
						{
							if ((vaild[k] & vaild[j]) == 0 && (place[1] & vaild[k]) == 0)
							{
								dp[2][j][k] = dp[1][k][0] + cn[j];
							}
							ans = max(ans, dp[2][j][k]);
						}
					}

				}
			}
			else
			{
				for (int j = 0; vaild[j] < 1 << m && j < cnt; j++)
				{
					if ((place[i] & vaild[j]) == 0)
					{
						for (int k = 0; vaild[k] < 1 << m && k < cnt; k++)
						{
							if ((vaild[k] & vaild[j]) == 0 && (place[i - 1] & vaild[k]) == 0)
							{
								for (int l = 0; vaild[l] < 1 << m && l < cnt; l++)
								{
									if ((vaild[k] & vaild[l]) == 0 && 
										(vaild[j] & vaild[l]) == 0 && 
										(place[i - 2] & vaild[l]) == 0)
									{
										dp[i][j][k] = max(dp[i][j][k], 
											dp[i - 1][k][l] + cn[j]);
									}
								}
							}
							ans = max(ans, dp[i][j][k]);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}