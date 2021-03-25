/*
Description:

Keywords: next_permutation

ULR: page 36
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT
int a[1001];

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef INTXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif

	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;	// 生成一个字典序最小的序列
		}

		int b = 1;
		do
		{
			if (b == m)
			{
				break;
			}
			b++;
		} while (next_permutation(a + 1, a + n + 1));

		for (int i = 1; i < n; i++)
		{
			cout << a[i] << " ";	// 输出第m大的字典序
		}

		cout << a[n] << endl;
	}

	return 0;
}