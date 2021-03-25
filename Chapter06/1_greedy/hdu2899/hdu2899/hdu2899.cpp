/*
Description: 退火模拟

Keywords: greedy

ULR: page 106
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;

#define INTXT

const double eps = 1e-8;		// 终止温度
double y;
double func(double x)
{
	return 6 * pow(x, 7.0) + 8 * pow(x, 6.0) +
		7 * pow(x, 3.0) + 5 * pow(x, 2.0) - y * x;
}

double solve()
{
	double T = 100;					// 初始温度
	double delta = 0.98;			// 降温系数
	double x = 50.0;				// x 的初始值
	double now = func(x);			// 计算初始函数值
	double ans = now;				// 返回值

	while (T > eps)					// eps 是终止温度
	{
		int f[2] = { 1,-1 };
		double newx = x + f[rand() % 2] * T;	// 按概率改变x, 随T的降温而减少

		if (newx >= 0 && newx <= 100)
		{
			double next = func(newx);
			ans = min(ans, next);
			if (now - next > eps)
			{
				x = newx;
				now = next;	//更新x
			}
		}

		T *= delta;
	}

	return ans;
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

	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%lf", &y);
		printf("%.4f\n", solve());
	}

	return 0;
}