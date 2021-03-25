/*
Description: 状态压缩dp

Keywords:

ULR: https://programmersought.com/article/64892474388/
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define INTXT

const int inf = 0x3f3f3f3f;
const int MAX = (1 << 15) + 10;

// t is the time it takes to reach i
// pre recorded path
// ddl as the deadline, len too long
int n, dp[MAX], t[MAX], pre[MAX], ddl[20], len[20];
char s[20][110];

void output(int x)
{
	if (!x)return;
	output(x - (1 << pre[x]));
	printf("%s\n", s[pre[x]]);
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

	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s%d%d", s[i], &ddl[i], &len[i]);

		// set the upper limit, 1 << n represents 2 ^ n
		int bit = 1 << n;

		for (int i = 1; i < bit; i++)
		{
			dp[i] = inf;
			for (int j = n - 1; j >= 0; j--)
			{
				int temp = 1 << j;
				// If the j-th bit is not 1 described can not be transferred from the i-temp over
				if (!(i&temp))
					continue;
				// points to a state on the length of time + - deadline
				int score = t[i - temp] + len[j] - ddl[j];
				// If you find you do not need negative points deduction
				if (score < 0)
					score = 0;

				if (dp[i] > dp[i - temp] + score)
				{
					// update dp
					dp[i] = dp[i - temp] + score;
					// update time spent
					t[i] = t[i - temp] + len[j];
					// record path
					pre[i] = j;
				}
			}
		}
		printf("%d\n", dp[bit - 1]);
		output(bit - 1);
	}

	return 0;
}