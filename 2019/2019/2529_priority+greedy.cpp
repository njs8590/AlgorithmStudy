//https://www.acmicpc.net/problem/2529

#define MAX 10
#include<iostream>
#include<stdio.h>

using namespace std;

int main(void) {
	int k;
	cin >> k;

	char arr[MAX];
	int num[MAX];
	for (int i = 0; i < 10; i++) {
		num[i] = 0;
	}

	int right = 0;
	int left = 0;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		arr[i] = temp;
		if (temp == '<') {
			right++;
			for (int j = 9; j >9-right; j--) {
				num[j]++;
			}
		}

		if (temp == '>') {
			left++;
			for (int j = 0; j < 0+left; j++) {
				num[j]++;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		char temp= arr[i];
		if (temp == '<') {
			int tail = 9;
			while (num[tail]) {
				tail--;
			}
			printf("%d", tail);
			for (int j = tail; j <= 9; j++) {
				num[j]--;
			}
		}
		else if (temp == '>') {
			int tail = 9;
			while (num[tail]) {
				tail--;
			}
			num[tail]--;
			printf("%d", tail);
		}
		else {
			printf("?");
		}
	}

	int tail = 9;
	while (num[tail]) {
		tail--;
	}
	printf("%d", tail);

	return 0;
}