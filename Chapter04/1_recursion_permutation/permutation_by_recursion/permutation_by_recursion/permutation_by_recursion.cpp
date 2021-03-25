/*
Description: 用loop写的permutation很丑, 用recursion则清晰明了

Keywords:

ULR: page 40
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT
#define Swap(a,b) {int temp = a; a = b; b = temp;}

int data1[] = { 1,2,3,4,5,6,8,9,32,15,18,33 };
//int num = 0;

int Perm(int begin, int end)
{
	static int num;

	if (begin == end)
	{
		num++;
	}
	else
	{
		for (int i = begin; i <= end; i++)
		{
			Swap(data1[begin], data1[i]);
			Perm(begin + 1, end);
			Swap(data1[begin], data1[i]);
		}
	}

	return num;
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

	cout << Perm(0, 9) << endl;	// 打印出排列总数, num = 10! 

	return 0;
}