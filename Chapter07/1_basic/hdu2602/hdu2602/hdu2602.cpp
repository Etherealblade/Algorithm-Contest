/*
Description: dp

Keywords:

ULR: page 126
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

struct BONE {
	int val;
	int vol;
}bone[1011];
int T, N, V;

// ================ version 1 ====================
int dp[1011][1011];
int ans() {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= V; j++) {
			if (bone[i].vol > j)   //第i个物品太大，装不了
				dp[i][j] = dp[i - 1][j];
			else                      //第i个物品可以装
				dp[i][j] = max(dp[i - 1][j],
					dp[i - 1][j - bone[i].vol] + bone[i].val);
		}
	return dp[N][V];
}

// ================ version 2 ====================
int dp1[1011];                     //替换 int dp1[1011][1011];
int ans1() {
	memset(dp1, 0, sizeof(dp1));
	for (int i = 1; i <= N; i++)
		for (int j = V; j >= bone[i].vol; j--)  //反过来循环
			dp1[j] = max(dp1[j], dp1[j - bone[i].vol] + bone[i].val);
	return dp1[V];
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

	cin >> T;
	while (T--) {
		cin >> N >> V;
		for (int i = 1; i <= N; i++)	cin >> bone[i].val;
		for (int i = 1; i <= N; i++)	cin >> bone[i].vol;
		cout << "V1: " << ans() << endl;
		cout << "V2: " << ans1() << endl;

	}

	return 0;
}
