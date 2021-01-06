/*
* problem: https://www.acmicpc.net/problem/2447
* algorithm: divide conquer , recursive

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined
void printstar(int y, int x, int size);
\
// global var
int N; // N = 3^k (1<=k<8)
vector<vector<string>> graph;

int main(void)
{
	cin >> N;

	graph.assign(N + 1, vector<string>());
	for (int i = 0; i <= N; i++) {
		graph[i].assign(N + 1, string());
	}

	printstar(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == "*")cout << graph[i][j];
			else cout << " ";
		}
		cout << endl;
	}

	return 0;
}

void printstar(int y, int x, int size)
{
	if (size == 1) graph[y][x] = "*";

	else {
		int nextsize = size / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int ny = y + i * nextsize;
				int nx = x + j * nextsize;

				if (i==1 && j==1 ) continue;

				printstar(ny, nx, nextsize);
			}
		}
	}
	
}
