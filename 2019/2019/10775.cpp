#define MAX 100007

#include<stdio.h>

int parent[MAX];

int find(int x) {
	if (x == parent[x]) {
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
	int G, P;
	scanf("%d %d", &G, &P);

	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	int gate;
	int answer = 0;

	for (int i = 0; i < P; i++) {
		scanf("%d", &gate);
		int validGate = find(gate);

		if (validGate != 0) {
			m_union(validGate, validGate-1);
			answer++;
		}
		else break;
	}

	printf("%d\n",answer);

	return 0;
}