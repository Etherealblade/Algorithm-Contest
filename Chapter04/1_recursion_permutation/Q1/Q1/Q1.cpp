/*
Description: 

Keywords: permutation

ULR: page 39
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef INTXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif
	
	int data[4] = { 5,2,1,4 };
	sort(data, data + 4);	// 排序, 得到最小排列

	do 
	{
		for (int i = 0; i < 4; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	} while (next_permutation(data, data+4));
	
	return 0;
}