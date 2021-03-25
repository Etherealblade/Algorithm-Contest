/*
Description: 分别用stack和queue模拟

Keywords: 

ULR: page29
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
	
	int t, n, temp;
	cin >> t;
	while (t--) {
		string str, str1;
		queue<int>Q;
		stack<int>S;
		cin >> n >> str;
		for (int i = 0; i < n; i++) {
			if (str == "FIFO") {                  //队列
				cin >> str1;
				if (str1 == "IN") {
					cin >> temp;  Q.push(temp);
				}
				if (str1 == "OUT") {
					if (Q.empty()) cout << "None" << endl;
					else {
						cout << Q.front() << endl;
						Q.pop();
					}
				}
			}
			else {                                //栈
				cin >> str1;
				if (str1 == "IN") {
					cin >> temp;  S.push(temp);
				}
				if (str1 == "OUT") {
					if (S.empty()) cout << "None" << endl;
					else {
						cout << S.top() << endl;
						S.pop();
					}
				}
			}
		}
	}
	
	return 0;
}