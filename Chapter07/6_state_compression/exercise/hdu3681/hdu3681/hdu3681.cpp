/*
Description: 状态压缩dp

Keywords:tsp + 二分, hard, no analysis is painful

ULR:
https://vjudge.net/problem/HDU-3681
https://programmersought.com/article/97172223518/
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define INTXT

char map1[16][16];
bool vis[16][16];
int cnt, dp[1 << 16][16];
struct Node {
	int x, y;
}node[16];
int dis[16][16][16][16];
const int inf = (1 << 30);
int n, m, fp, head, tail;
int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
Node que[400];
int endfor;

bool ok(int x, int y) {
	if (x >= 0 && x < n&&y >= 0 && y < m &&
		map1[x][y] != 'D' && !vis[x][y]) return true;
	return false;
}

void bfs(Node start) {
	Node tmp;
	vis[start.x][start.y] = true;
	que[tail++] = start;
	int step = 0;
	while (head < tail) {
		int sz = tail - head;
		step++;
		while (sz--) {
			Node ss = que[head++];
			for (int i = 0; i < 4; i++) {
				tmp.x = ss.x + dir[i][0];
				tmp.y = ss.y + dir[i][1];
				if (ok(tmp.x, tmp.y)) {
					if (map1[tmp.x][tmp.y] == 'G' || map1[tmp.x][tmp.y] == 'Y') {
						dis[start.x][start.y][tmp.x][tmp.y] = step;
						//		cout<<start.x<<" "<<start.y<<" "<<tmp.x<<" "<<tmp.y<<" "<<step<<endl;
					}
					que[tail++] = tmp;
					vis[tmp.x][tmp.y] = true;
				}
			}
		}
	}
}

bool check(int bat) {
	memset(dp, -1, sizeof(dp));
	int alt = 1 << cnt;
	dp[1 << fp][fp] = bat;
	for (int i = 0; i < alt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (dp[i][j] == -1) continue;
			if ((i&endfor) == endfor) {
				if (dp[i][j] != -1) return true;
			}
			for (int k = 0; k < cnt; k++) {
				if (dis[node[j].x][node[j].y][node[k].x][node[k].y] == -1) continue;
				if (i&(1 << k)) continue;
				if (dp[i][j] - dis[node[j].x][node[j].y][node[k].x][node[k].y] < 0) continue;
				int tmp = dp[i][j] - dis[node[j].x][node[j].y][node[k].x][node[k].y];
				if (map1[node[k].x][node[k].y] == 'G') tmp = bat;
				if (tmp > dp[i | (1 << k)][k]) dp[i | (1 << k)][k] = tmp;
			}
		}
	}
	return false;
}


void slove() {
	int l = 0, r = 1000;
	int res = r;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	if (res == 1000) printf("-1\n");
	else printf("%d\n", res);
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

	while (scanf("%d%d", &n, &m), n || m) {
		cnt = 0;
		endfor = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", map1[i]);
			for (int j = 0; j < m; j++) {
				if (map1[i][j] == 'F') {
					fp = cnt;
					node[cnt].x = i, node[cnt].y = j;
					cnt++;
				}
				else if (map1[i][j] == 'G') {
					node[cnt].x = i, node[cnt].y = j;
					cnt++;
				}
				else if (map1[i][j] == 'Y') {
					node[cnt].x = i, node[cnt].y = j;
					endfor += (1 << cnt);
					cnt++;
				}
			}
		}
		memset(dis, -1, sizeof(dis));
		for (int i = 0; i < cnt; i++) {
			head = tail = 0;
			memset(vis, false, sizeof(vis));
			bfs(node[i]);
		}
		slove();
	}

	return 0;
}