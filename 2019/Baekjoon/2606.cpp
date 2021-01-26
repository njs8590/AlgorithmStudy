//바이러스
//https://www.acmicpc.net/problem/2606

#define MAX 107

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int parent[MAX];
bool connect[MAX];

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
	int computer_cnt;
	scanf("%d", &computer_cnt);
	int network_cnt;
	scanf("%d", &network_cnt);

	//init
	for (int i = 1; i <= computer_cnt; i++) {
		parent[i] = i;
	}

	int first, second;
	for (int i = 0; i < network_cnt; i++) {
		scanf("%d %d", &first, &second);
		m_union(first, second);
		//print
		for (int j = 0; j < 10; j++) {
			printf("%d ", parent[j]);
		}
		cout << endl;
	}

	//find answer
	int answer = 0;
	for (int i = 2; i <= computer_cnt; i++) {
		if (find(i) == find(1)) {
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}