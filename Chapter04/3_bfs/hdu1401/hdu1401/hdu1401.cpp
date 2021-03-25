/*
Description:

Keywords:

ULR:
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

typedef long long ll;
struct pos
{
	int x, y;
};

pos a[4], b[4];
int loc[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
map<ll, int>vis[2];
struct node
{
	int step;
	pos a[4];
};

int compare(pos a, pos b)
{
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

ll change(pos a[])
{
	sort(a, a + 4, compare);
	ll ans = 0;
	for (int i = 0; i < 4; i++)
	{
		ans |= (a[i].x << (6 * i));
		ans |= (a[i].y << (6 * i + 3));
	}
	return ans;
}

int judge(pos a)
{
	if (a.x >= 0 && a.x < 8 && a.y >= 0 && a.y < 8) return 1;
	return 0;
}

int isSame(pos a[], int x)
{
	for (int i = 0; i < 4; i++)
	{
		if (i != x && a[i].x == a[x].x&&a[i].y == a[x].y) return 1;
	}
	return 0;
}

queue<node>q[2];

int bfs(int x)
{
	node now, next;
	int Size = q[x].size();
	while (Size--)
	{
		now = q[x].front(); q[x].pop();
		ll t = change(now.a);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				next = now;
				next.step++;
				next.a[i].x += loc[j][0];
				next.a[i].y += loc[j][1];
				if (judge(next.a[i]))
				{
					if (isSame(next.a, i))
					{
						next.a[i].x += loc[j][0];
						next.a[i].y += loc[j][1];
						if (judge(next.a[i]))
						{
							if (!isSame(next.a, i))
							{
								ll t = change(next.a);
								if (vis[x ^ 1][t] == 1)
								{
									return 1;
								}
								else
								{
									vis[x][t] = 1;
									q[x].push(next);
								}
							}
						}
					}
					else
					{
						ll t = change(next.a);
						if (vis[x ^ 1][t] == 1)
						{
							return 1;
						}
						else
						{
							vis[x][t] = 1;
							q[x].push(next);
						}
					}
				}
			}
		}
	}
	return 0;
}

int tbfs()
{
	node now1, now2;
	for (int i = 0; i < 4; i++)
	{
		now1.a[i] = a[i];
		now2.a[i] = b[i];
	}
	q[0].push(now1);
	ll t1 = change(now1.a);
	vis[0][t1] = 1;
	q[1].push(now2);
	ll t2 = change(now2.a);
	vis[1][t2] = 1;
	if (t1 == t2) return 1;
	int step = 0;
	while (!q[0].empty() || !q[1].empty())
	{
		if (step >= 4) return 0;
		step++;
		if (bfs(0)) return 1;
		if (bfs(1)) return 1;
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

	while (scanf("%d%d", &a[0].x, &a[0].y) != EOF)
	{
		vis[0].clear(); vis[1].clear();
		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();
		scanf("%d%d%d%d%d%d", &a[1].x, &a[1].y, &a[2].x, &a[2].y, &a[3].x, &a[3].y);
		for (int i = 0; i < 4; i++) a[i].x--, a[i].y--;
		for (int i = 0; i < 4; i++)
		{
			scanf("%d%d", &b[i].x, &b[i].y);
			b[i].x--, b[i].y--;
		}
		if (tbfs()) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}