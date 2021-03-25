/*
Description: 4.1节问题3. 打印n个数中任意m个数的组合

Keywords:

ULR: page 43
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

void combination(int n, int k)
{
	for (int i = 0; i < (1 << n); i++)
	{
		int num = 0, kk = i;	//num统计i中1的个数, kk用来处理i
		while (kk)
		{
			kk = kk & (kk - 1);	//清除kk中最后一个1
			num++;		//统计1的个数
		}

		if (num == k)
		{
			for (int j = 0; j < n; j++)
			{
				if (i&(1 << j))
				{
					cout << j << " ";
				}
			}
			cout << endl;
		}

	}
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

	int n, k;
	cin >> n >> k;
	combination(n, k);

	return 0;
}