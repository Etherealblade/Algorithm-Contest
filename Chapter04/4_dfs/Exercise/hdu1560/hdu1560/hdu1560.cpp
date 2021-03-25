/*
Description: dna sequence

Keywords: ida*

ULR:
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

typedef long long ll;
const ll N = 40;
char ss[10][10];
ll pos[N], len[N];
char dic[4] = { 'A', 'C', 'G', 'T' };
bool dfs(ll d, ll n, ll maxD) {
	ll leftNum = 0;
	for (ll i = 0; i < n; ++i)
		leftNum = max(leftNum, len[i] - pos[i]);
	if (leftNum == 0)return 1;
	if (leftNum + d > maxD)return 0;
	bool visit[10];
	for (ll i = 0; i < 4; ++i) {
		memset(visit, 0, sizeof(visit));
		for (ll j = 0; j < n; ++j)
			if (ss[j][pos[j]] == dic[i])++pos[j], visit[j] = 1;
		if (dfs(d + 1, n, maxD))return 1;
		for (ll j = 0; j < n; ++j)
			if (visit[j])--pos[j];
	}
	return 0;
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

	ll t, n;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		ll maxD = 0;
		for (ll i = 0; i < n; ++i) {
			scanf("%s", ss[i]);
			ll l = strlen(ss[i]);
			len[i] = l, maxD = max(maxD, l);
		}
		memset(pos, 0, sizeof(pos));
		for (; !dfs(0, n, maxD); ++maxD);
		printf("%lld\n", maxD);
	}

	return 0;
}