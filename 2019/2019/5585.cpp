//거스름돈
//그리디 알고리즘
//https://www.acmicpc.net/problem/5585

#include<iostream>
using namespace std;

int main(void) {
	int money;
	cin >> money;

	int answer = 0;

	money = 1000 - money;

	int arr[5] = { 500, 100, 10, 5, 1};
	for (int i = 0; i < 5; i++) {
		int temp = money / arr[i];
		if (temp > 0) {
			money -= arr[i] * temp;
			answer += temp;
		}
	}

	cout << answer << endl;
	return 0;
}