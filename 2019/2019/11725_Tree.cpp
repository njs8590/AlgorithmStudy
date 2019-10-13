//https://www.acmicpc.net/problem/11725

#define MAX 100007

#include<iostream>
#include<stdio.h>

using namespace std;

int parentList[MAX];

int main(void) {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int child, parent;
		scanf("%d %d", &parent, &child);
		parentList[child] = parent;
	}

	for (int i = 1; i <= N; i++) {
		cout << parentList[i] << endl;
	}

	return 0;
}