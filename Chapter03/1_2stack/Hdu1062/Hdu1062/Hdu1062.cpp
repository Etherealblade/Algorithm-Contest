/*
Description: 小心爆栈

Keywords: stack

ULR: page27
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

	int n;
	char ch;
	scanf("%d", &n);  
	getchar();
	while (n--) {
		stack<char> s;
		while (true) {
			ch = getchar();                   //一次读入一个字符
			if (ch == ' ' || ch == '\n' || ch == EOF) {
				while (!s.empty()) {
					printf("%c", s.top());		//输出栈顶
					s.pop();					//清除栈顶
				}
				if (ch == '\n' || ch == EOF)  
					break;
				printf(" ");
			}
			else   
				s.push(ch);					//入栈
		}
		printf("\n");
	}

	return 0;
}