/*****
kakao code festival 예선2
인형들
https://www.acmicpc.net/problem/15954

*****/


#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

//global var
int N, K;
long double arr[510];
//function predefined
long double mean(long double  arr[], long double cnt);
long double variation(long double arr[],long double cnt, long double m);

int main(void) {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	long double answer = 999999999999999999;

	for (int i = 0; i <= N - K; i++) {
		for (int j = K; j <= N - i; j++) {
			long double m = mean(arr + i, (long double)j);
			long double candi = variation(arr + i,(long double)j, m);
			//printf("%f", candi);
			if (answer > candi) {
				answer = candi;
			}
		}
	}

	printf("%.11f\n", sqrt(answer));

	return 0;
}

long double mean(long double arr[], long double cnt) {
	long double sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += arr[i];
		//cout << arr[i] << " ";
	}
	return sum / cnt;
}

long double variation(long double arr[],long double cnt, long double m) {

	long double var = 0;
	for (int i = 0; i < cnt; i++) {
		var += (arr[i] - m) * (arr[i] - m);
	}
	return var / cnt;
}