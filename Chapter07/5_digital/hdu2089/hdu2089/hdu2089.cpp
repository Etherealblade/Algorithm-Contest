/*
Description: digital DP

Keywords:

ULR: page 146
*/

#include <bits/stdc++.h>
#pragma warning(disable: 4996)
using namespace std;
#define INTXT

const int MAX = 10;
int dp[MAX][MAX], digit[MAX];

void Init()
{
	dp[0][0] = 1;
	for (int DigitNum = 1; DigitNum <= 7; DigitNum++)
	{
		for (int FirDigit = 0; FirDigit < 10; FirDigit++) // enumerates the value of the highest bit
		{
			for (int SecDigit = 0; SecDigit < 10; SecDigit++) // Enumerate the next highest bit, skip if there is an unlucky situation, otherwise accumulate
			{
				if ((FirDigit == 6 && SecDigit == 2) || FirDigit == 4)   continue;
				dp[DigitNum][FirDigit] += dp[DigitNum - 1][SecDigit];
			}
		}
	}
	return;
}

int CalLen(int x) //Seeking a number with a few digits
{
	int len = 0;
	while (x)
	{
		len++;
		x /= 10;
	}
	return len;
}

void CalDigit(int num, int len)
{
	memset(digit, 0, sizeof(digit));
	for (int i = 1; i <= len; i++)
	{
		digit[i] = num % 10;
		num /= 10;
	}
}

int Solve(int n) // Find the number of qualified conditions from 0 to n
{
	int ans = 0;
	int len = CalLen(n);
	CalDigit(n, len);
	for (int DigitNum = len; DigitNum >= 1; DigitNum--) //Enumerate from the highest bit
	{
		for (int Digit = 0; Digit < digit[DigitNum]; Digit++) // enumerate the highest bit
			if (!(Digit == 2 && digit[DigitNum + 1] == 6) && Digit != 4) //Eligible to add
				ans += dp[DigitNum][Digit];
		if (digit[DigitNum] == 4 || (digit[DigitNum] == 2 &&
			digit[DigitNum + 1] == 6)) //The current one has not met the condition, then the following digits are enumerated no matter how Also unqualified
			break;
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

	Init();
	int n, m;
	while (cin >> n >> m, n + m)
		cout << Solve(m + 1) - Solve(n) << endl;

	return 0;
}