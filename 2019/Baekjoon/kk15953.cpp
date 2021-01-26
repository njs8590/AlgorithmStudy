/*****
kakao code festival 예선1
상금헌터
https://www.acmicpc.net/problem/15953

*****/


#include<iostream>

using namespace std;

int testcase;

int main(void)
{
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int a, b;
		cin >> a >> b;

		int res_a, res_b;
		res_a = res_b = 0;

		if (a == 1) {
			res_a = 5000000;
		}
		else if (a >= 2 && a <= 3) {
			res_a = 3000000;
		}
		else if (a >= 4 && a <= 6) {
			res_a = 2000000;
		}
		else if (a >= 7 && a <= 10) {
			res_a = 500000;
		}
		else if (a >= 11 && a <= 15) {
			res_a = 300000;
		}
		else if (a >= 16 && a <= 21) {
			res_a = 100000;
		}

		if (b == 1) {
			res_b = 5120000;
		}
		else if (b >= 2 && b <= 3) {
			res_b = 2560000;
		}
		else if (b >= 4 && b <= 7) {
			res_b = 1280000;
		}
		else if (b >= 8 && b <= 15) {
			res_b = 640000;
		}
		else if (b >= 16 && b <= 31) {
			res_b = 320000;
		}

		cout << res_a + res_b << endl;
	}
	return 0;
}