//집합의 표현
//https ://www.acmicpc.net/problem/1717

#define MAX 10000007
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
	int n, m;
	scanf("%d %d", &n, &m);
	//수 범위가 1~n

	//init
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int op, first, second;
		scanf("%d %d %d", &op, &first, &second);
		if (op == 0) {
			m_union(first, second);
		}
		else if (op == 1) {
			if (find(first) == find(second)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}