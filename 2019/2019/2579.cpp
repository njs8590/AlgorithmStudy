//https://www.acmicpc.net/problem/2579
//계단을 처음부터 끝까지 올라가는데 득점할 수 있는 최대값
//계단은 한칸 혹은 두칸 올라갈 수 있다.
//연속해서 세칸은 밟을 수 없다.

#include<stdio.h>

int max(int x, int y) {
	return x > y ? x : y;
}

int main(void) {
	
	int cnt;
	int arr[305];

	scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		scanf("%d", &arr[i]);
	}

	int dp[305];
	dp[1] = arr[1];
	dp[2] = max(arr[1] + arr[2], arr[2]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	
	for (int i = 4; i <= cnt; i++) {
		//점화식 만들기 겁나어렵다..
		dp[i] = max( dp[i-3]+arr[i-1]+arr[i], dp[i - 2] + arr[i]);
		//3칸전까지 올라온 최대값 + 2칸오르고+ 목적지 오르고
		//2칸전까지 올라온 최대값 + 2칸(목적지) 오르고
	}

	/*for (int i = 1; i <= cnt; i++) {
		printf("%d ", dp[i]);
	}*/

	printf("%d\n", dp[cnt]);

	return 0;
}