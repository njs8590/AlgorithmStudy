//https://www.acmicpc.net/problem/2579
//����� ó������ ������ �ö󰡴µ� ������ �� �ִ� �ִ밪
//����� ��ĭ Ȥ�� ��ĭ �ö� �� �ִ�.
//�����ؼ� ��ĭ�� ���� �� ����.

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
		//��ȭ�� ����� �̳���ƴ�..
		dp[i] = max( dp[i-3]+arr[i-1]+arr[i], dp[i - 2] + arr[i]);
		//3ĭ������ �ö�� �ִ밪 + 2ĭ������+ ������ ������
		//2ĭ������ �ö�� �ִ밪 + 2ĭ(������) ������
	}

	/*for (int i = 1; i <= cnt; i++) {
		printf("%d ", dp[i]);
	}*/

	printf("%d\n", dp[cnt]);

	return 0;
}