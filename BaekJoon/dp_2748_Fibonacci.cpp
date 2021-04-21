/*
* problem:
* algorithm:
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

// typedef

// function pre-defined
long long fibo(int n);

// global var
long long dp[100];


long long fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (dp[n] == -1) {
		dp[n] = fibo(n-1) + fibo(n-2);
	}
	else {
		return dp[n];
	}

	return dp[n];
}

int main(void)
{
	for (int i = 0; i < 100; i++)dp[i] = -1;
	dp[0] = 0;
	dp[1] = 1;

	int n;
	cin >> n;
	cout << fibo(n) << endl;;

	return 0;
}