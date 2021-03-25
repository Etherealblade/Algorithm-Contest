/*
Description: 2^n

Keywords:

ULR: page 42
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

//#define INTXT

void print_subset(int n)
{
	for (int i = 0; i < (1 << n); i++)
	{
		// 1~2^n, 每个i的二进制对应一个子集, 一次打印一个子集, 最后得到all subsets
		for (int j = 0; j < n; j++)
		{
			// 打印一个子集, 即打印i的二进制数中所有的1
			if (i&(1 << j))
			{
				// 从i的最低位开始逐个检查每一位, 如果是1, 打印
				cout << j << " ";
			}
		}

		cout << endl;
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

	int n;
	cin >> n;
	print_subset(n);

	return 0;
}