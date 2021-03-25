/*
Description: 区间 DP, 石子合并

Keywords:

ULR: page 135
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

const int INF = 1 << 30;
const int N = 300;
int sum[N], n;

// ============ version 1 ===============
int Minval() {
	int dp[N][N];
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;
	for (int len = 1; len < n; len++)       //len是i和j之间的距离
		for (int i = 1; i <= n - len; i++) {  //从第i堆开始
			int j = i + len;               //到第j堆结束
			dp[i][j] = INF;
			for (int k = i; k < j; k++)         //i和j之间，用k进行分割
				dp[i][j] = min(dp[i][j],
					dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
		}
	return dp[1][n];
}

// ============ version 2, incorrect ===============
int Minval1() {     //平行四边形优化
	int dp1[N][N], s[N][N];
	for (int i = 1; i <= n; i++) {
		dp1[i][i] = 0;
		s[i][i] = i;               //初始值
	}
	for (int len = 1; len < n; len++)
		for (int i = 1; i <= n - len; i++) {
			int j = i + len;
			dp1[i][j] = INF;
			for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++)  //缩小范围
				if (dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1] < dp1[i][j]) {
					dp1[i][j] = dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1];
					s[i][j] = k;      //记录[i, j]的最优分割点
				}
		}
	return dp1[1][n];
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

	while (cin >> n) {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sum[i] = sum[i - 1] + x;       //sum[i,j]的值等于 sum[j]-sum[i-1]
		}
		cout << "V1: " << Minval() << endl;
		cout << "V2: " << Minval1() << endl;

	}

	return 0;
}