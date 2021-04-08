//여행가자
//https ://www.acmicpc.net/problem/1976

#define MAX 207

#include<iostream>
#include<stdio.h>

using namespace std;

int parent[MAX];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void m_union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}

}
int main(void) {
	int N, M;

	scanf("%d %d",&N,&M);

	int graph[MAX][MAX];

	int temp;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &temp);
			graph[i][j] = temp;
			if (temp == 1) {
				m_union(i, j);
			}
		}
	}

	int answer;
	int first;
	scanf("%d", &first);
	answer = find(first);
	int second;
	bool find_answer = true;
	for (int i = 1; i < M; i++) {
		scanf("%d", &second);
		if (answer != find(second)) {
			find_answer = false;
			break;
		}
	}
	if (find_answer) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}