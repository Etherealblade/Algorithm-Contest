/*
Description: 定义集合A, B把所有人放进集合A, 把所有有失败记录的放进集合B.
if A-B=1, 则可以判断存在冠军, 否则不能!

Keywords: set

ULR: page 32
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
	
	set<string> A, B;	//定义集合
	string s1, s2;
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			A.insert(s1);  A.insert(s2);		//所有人放进集合A
			B.insert(s2);						//失败者放进集合B
		}
		if (A.size() - B.size() == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		A.clear(); B.clear();
	}
	
	return 0;
}