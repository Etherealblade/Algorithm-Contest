/*
Description: lcm

Keywords:

ULR: page 324
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int solve(long long ex, long long ey) {
	int ans = 1;
	long long t;
	while (true) {
		if (ex > ey)
			std::swap(ex, ey);
		t = gcd(ex, ey);
		//p = ex / t;  q= ey/(ex+t);	//计算中p和q并未用到。
		if ((ey % (ex + t)) == 0) {		//判断q是否整数；t和p肯定是整数不用判断。
			ey = ey * t / (ex + t);
			ans++;
		}
		else
			break;
	}
	return ans;
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
	long long ex, ey;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%lld%lld", &ex, &ey);
		printf("Case #%d: %d\n", cas, solve(ex, ey));
	}

	return 0;
}