/*
Description: the rotation game

Keywords: ida*

ULR:
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

int map1[8][8], step;
char road[100];
int hash1[8] = { 3,5,3,5,5,3,5,3 };
void TurnCOL(int c, int flag) // rotatable column, c denotes a column where, flag indicates up or down, up 1 represents
{
	int t;
	if (flag)
	{
		t = map1[1][c];
		for (int i = 2; i <= 7; i++)
			map1[i - 1][c] = map1[i][c];
		map1[7][c] = t;
	}
	else {
		t = map1[7][c];
		for (int i = 6; i >= 1; i--)
			map1[i + 1][c] = map1[i][c];
		map1[1][c] = t;
	}
}
void TurnROW(int r, int flag) // row rotation, r represents row, flag indicates the right or to the left, to the right represents 1
{
	int t;
	if (flag)
	{
		t = map1[r][7];
		for (int i = 6; i >= 1; i--)
			map1[r][i + 1] = map1[r][i];
		map1[r][1] = t;
	}
	else {
		t = map1[r][1];
		for (int i = 2; i <= 7; i++)
			map1[r][i - 1] = map1[r][i];
		map1[r][7] = t;
	}
}
int check()
{
	int num[4] = { 0 };
	for (int i = 3; i <= 5; i++)
	{
		num[map1[3][i]]++;
		num[map1[5][i]]++;
	}
	num[map1[4][3]]++;
	num[map1[4][5]]++;
	int t = max(num[1], max(num[2], num[3]));
	return t;
}
bool dfs(int cnt)
{
	int t = check();
	if (t == 8 && cnt == step)
		return true;
	if (cnt + (8 - t) > step)
		return false;
	char c;
	for (int i = 0; i < 8; i++)
	{
		c = i + 'A';
		road[cnt] = c;
		if (c == 'A' || c == 'B')
		{
			TurnCOL(hash1[i], 1);
			if (dfs(cnt + 1)) return true;
			TurnCOL(hash1[i], 0);
		}
		else if (c == 'F' || c == 'E')
		{
			TurnCOL(hash1[i], 0);
			if (dfs(cnt + 1))return true;
			TurnCOL(hash1[i], 1);
		}
		else if (c == 'C' || c == 'D')
		{
			TurnROW(hash1[i], 1);
			if (dfs(cnt + 1)) return true;
			TurnROW(hash1[i], 0);
		}
		else {
			TurnROW(hash1[i], 0);
			if (dfs(cnt + 1)) return true;
			TurnROW(hash1[i], 1);
		}
	}
	return false;
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

	int a, b;
	while (scanf("%d", &a) == 1 && a)
	{
		scanf("%d", &b);
		memset(map1, 0, sizeof(map1));
		map1[1][3] = a;
		map1[1][5] = b;
		for (int i = 2; i <= 7; i++)
		{
			if (i == 3 || i == 5)
			{
				for (int j = 1; j <= 7; j++)
					scanf("%d", &map1[i][j]);
				continue;
			}
			scanf("%d %d", &map1[i][3], &map1[i][5]);
		}
		if (check() == 8)
		{
			puts("No moves needed");
			printf("% d \ n", map1[3][3]);
			continue;
		}
		step = 1;
		while (true)
		{
			if (dfs(0))
				break;
			step++;
		}
		road[step] = '\0';
		puts(road);
		printf("%d\n", map1[3][3]);
	}

	return 0;
}