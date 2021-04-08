/*
* problem: https://www.acmicpc.net/problem/11053
* algorithm:

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined

// global var
int N; // ������ ũ��
int A[1001]; // ����

int main(void)
{
	int dp[1001];
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		dp[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int cur = A[i];
		int max = 0;
		for (int j = 0; j < i; j++) {
			// cur ���� �����ֵ��̸� dp���� ���Ѵ�
			if (A[j] < cur) {
				if (max < dp[j])max = dp[j];
			}
		}
		dp[i] += max;
		if (dp[i] > answer)answer = dp[i];
	}

	cout << answer << endl;

	return 0;
}
