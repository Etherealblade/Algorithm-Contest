﻿/*
Description:

Keywords: list

ULR: page 30
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

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int k = 2;
		list<int> mylist;             //定义
		list<int>::iterator it;
		for (int i = 1; i <= n; i++)
			mylist.push_back(i);     //赋值
		while (mylist.size() > 3) {
			int num = 1;
			for (it = mylist.begin(); it != mylist.end(); ) {
				if (num++ % k == 0)
					it = mylist.erase(it);
				else
					it++;
			}
			k == 2 ? k = 3 : k = 2;            //1至2报数，1至3报数
		}
		for (it = mylist.begin(); it != mylist.end(); it++) {
			if (it != mylist.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
	}

	return 0;
}