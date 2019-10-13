//그리디 알고리즘
//https://www.acmicpc.net/problem/11399
//ATM

#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	
	int arr[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr, arr + n);

	int answer = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		answer += sum;
	}

	printf("%d\n",answer);

	return 0;
}