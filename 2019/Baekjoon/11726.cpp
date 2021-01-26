//https://www.acmicpc.net/problem/11726

#include<stdio.h>

int main(void) {
	int dp[1001];

	dp[1] = 1;
	dp[2] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	printf("%d\n",dp[n]%10007);

	return 0;
}