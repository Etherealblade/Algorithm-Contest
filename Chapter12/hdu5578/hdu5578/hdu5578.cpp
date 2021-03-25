/*
Description: 暴力, naive

Keywords:

ULR: page 318
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

const int N = 100010;
char s[N];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int ans = -1;
	for (int i = 0; i < n; ++i) {  //从头到尾检查字符串，i是当前位置
		for (int j = 1; j <= 26 && i - j >= 0; ++j) {
			//剪枝技巧：由于小写字符一共有26个，所以字符串中两个相
			//同字符的最小距离不会大于26，只需要检查i前面的26个字符
			if (s[i] == s[i - j]) {
				//j从1开始递增，即从距离i最近的字符开始检查，
				//如果有相同字符，就break；其它未检查的距离更大，不用继续检查。
				if (ans == -1 || j < ans) {
					ans = j;
				}
				break;
			}
		}
	}
	printf("%d\n", ans);
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

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}