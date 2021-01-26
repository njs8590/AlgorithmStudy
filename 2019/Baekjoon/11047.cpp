//동전교환
//그리디
//https://www.acmicpc.net/problem/11047

#include<stdio.h>
#include<iostream>

using namespace std;

int main(void) {
	int N;
	long long K;
	long long arr[11];

	scanf("%d", &N);
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	for (int i = N - 1; i >= 0; i--) {
		long long temp = K / arr[i];
		if (temp > 0) {
			answer += temp;
			K -= arr[i] * temp;
		}
		if (K == 0)break;
	}

	cout << answer << endl;
	

	return 0;
}