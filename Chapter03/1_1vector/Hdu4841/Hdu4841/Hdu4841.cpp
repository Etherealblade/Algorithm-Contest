/*
Description:
Josephus 变种, 用vector模拟动态变化的圆桌, 赶走n个人之后留下的都是好人

Keywords:

ULR:
*/

#include <bits/stdc++.h>
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

	vector <int> table;								//模拟圆桌
	int n, m;
	while (cin >> n >> m) {
		table.clear();
		for (int i = 0; i < 2 * n; i++)  
			table.push_back(i);	//初始化
		int pos = 0;                               //记录当前位置
		for (int i = 0; i < n; i++) 
		{
			//赶走n个
			pos = (pos + m - 1) % table.size();	//圆桌是个环，取余处理
			table.erase(table.begin() + pos);	//赶走坏人，table人数减1
		}
		int j = 0;
		for (int i = 0; i < 2 * n; i++)
		{	
			//打印预先安排座位
			if (!(i % 50) && i)  
				cout << endl;       //50个字母一行
			if (j < table.size() && i == table[j]) 
			{	
				//table留下的都是好人
				j++;
				cout << "G";
			}
			else
				cout << "B";
		}
		cout << endl;	//留一个空行
	}

	return 0;
}