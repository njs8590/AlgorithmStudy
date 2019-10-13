//https://www.acmicpc.net/problem/9095

#include<iostream>

using namespace std;

int main(void){

	int testcase;
	cin >> testcase;

	int dp[100];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < testcase; i++) {
		int n;
		cin >> n;

		cout << dp[n] << endl;
	}
	return 0;
}