/*
* problem: https://www.acmicpc.net/problem/1932
* algorithm: DP

*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined

// global var


int main(void)
{
	// var
	int n; // 삼각형의 크기
	long long answer = 0;

	vector<vector<int>> dp, map;

	// input
	cin >> n;
	
	dp.assign(n, vector<int>());
	map.assign(n, vector<int>());

	// init
	for (int i = 0; i < n; i++) {
		dp[i].assign(i + 1, 0);
		map[i].assign(i + 1, 0);

		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	// dp
	dp[0][0] = map[0][0];
	answer = dp[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) { // 위 노드만 존재
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
			else if (j == i) { // 왼쪽 위 노드만 존재
				dp[i][j] = dp[i - 1][j - 1] + map[i][j];
			}
			else { // 위, 왼쪽위 노드 2개 존재 (정상케이스)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + map[i][j];
			}

			if (answer < dp[i][j]) answer = dp[i][j];
		}
	}

	cout << answer << endl;


	return 0;
}