//https://www.acmicpc.net/problem/1463
//1¸¸µé±â

#include<stdio.h>

int min(int x, int y) {return x < y ? x : y;}

int dp[1000001];

int main(void) {

	int i, n;
	scanf("%d", &n);

	dp[0] = dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	printf("%d\n", dp[n]);

	return 0;
}