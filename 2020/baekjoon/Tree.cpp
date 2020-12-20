/*
* https://www.acmicpc.net/problem/4803
* Tree 
*/

#include<iostream>
#include<stdio.h>
#include<vector>

#define NODEMAX 501

using namespace std;

// function pre-defined
int DFS(int cur, int prev);
void init();

// global var
bool visited[NODEMAX];
int n, m;
vector <vector<int>> edge;
int answer;
int tree;

int main(void)
{
	for (int testcase = 1;; testcase++)
	{
		n = 0; m = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)break;

		init();

		for (int i = 0; i < m; i++) {
			int node1, node2;
			cin >> node1 >> node2;

			edge[node1].push_back(node2);
			edge[node2].push_back(node1);
		}

		for (int start = 1; start <= n; start++)
		{
			if (!visited[start]) answer += DFS(start, 0);
		}

		printf("Case %d: ", testcase);
		if (answer == 0) {
			printf("No trees.\n");
		}
		else if (answer == 1) {
			printf("There is one tree.\n");
		}
		else {
			printf("A forest of %d trees.\n", answer);
		}
	}

	return 0;
}

int DFS(int cur, int prev)
{
	visited[cur] = true;

	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];
		if (next == prev) continue;
		if (visited[next]) return 0; // cycle
		if (DFS(next, cur) == 0) return 0;
	}
	return 1;
}

void init()
{
	tree = 0;
	answer = 0;
	edge.assign(n + 1, vector<int>());
	for (int i = 0; i < NODEMAX; i++) visited[i] = false;
}
