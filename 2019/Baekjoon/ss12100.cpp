/******************
https://www.acmicpc.net/problem/12100
2048
N * N 그래프
상하좌우로 움직일 수 있음.
5번 이동시켜서 만들 수 있는 최대값.
0은 빈칸, 이외는 그래프의 성분값
*******************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//func
void dfs(int dir, int count);
void print();
void backup(int from[21][21], int to[21][21]);

//global var
int graph[21][21];
int N;
int answer = -1;


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	dfs(-1, 0);

	printf("%d\n", answer);

	return 0;

}

void dfs(int dir, int count)
{

	int visited[21][21] = { 0, };
	//움직여

	//상
	if (dir == 0) {

		bool is_updated = true;
		while (is_updated == true) {
			
			is_updated = false;
			for (int i = 1; i < N; i++) {	//위에서 두번째줄부터 아래로
				for (int j = 0; j < N; j++) {
					if (graph[i][j] == 0)continue;

					int cur, next;
					cur = graph[i][j];
					next = graph[i - 1][j];
					
					if (next == 0) {
						graph[i][j] = 0;
						graph[i - 1][j] = cur;
						is_updated = true;
					}
					else if (cur == next) {
						if (visited[i - 1][j] == 1)continue;	//한큐에한번만 합칠수있음.
						graph[i][j] = 0;
						graph[i - 1][j] = cur + next;
						visited[i - 1][j] = 1;
						is_updated = true;
						
					}
				}
			}
		}
	}
	//하
	if (dir == 1) {
		bool is_updated = true;
		while (is_updated == true) {

			is_updated = false;
			for (int i = N-2; i>=0; i--) {	//아래에서 두번째부터 위로
				for (int j = 0; j < N; j++) {
					if (graph[i][j] == 0)continue;

					int cur, next;
					cur = graph[i][j];
					next = graph[i+1][j];

					if (next == 0) {
						graph[i][j] = 0;
						graph[i+1][j] = cur;
						is_updated = true;
					}
					else if (cur == next) {
						if (visited[i+1][j] == 1)continue;	//한큐에한번만 합칠수있음.
						graph[i][j] = 0;
						graph[i+1][j] = cur + next;
						visited[i+1][j] = 1;
						is_updated = true;

					}
				}
			}
		}
	}
	//좌
	if (dir == 2) {
		bool is_updated = true;
		while (is_updated == true) {

			is_updated = false;
			for (int i = 0; i < N; i++) {
				for (int j = 1; j < N; j++) {	//왼쪽에서 두번째부터 오른쪽으로
					if (graph[i][j] == 0)continue;
					
					int cur, next;
					cur = graph[i][j];
					next = graph[i][j-1];

					if (next == 0) {
						graph[i][j] = 0;
						graph[i][j-1] = cur;
						is_updated = true;
					}
					else if (cur == next) {
						if (visited[i][j-1] == 1)continue;	//한큐에한번만 합칠수있음.
						graph[i][j] = 0;
						graph[i][j-1] = cur + next;
						visited[i][j-1] = 1;
						is_updated = true;

					}
				}
			}
		}
	}
	//우
	if (dir == 3) {
		bool is_updated = true;
		while (is_updated == true) {

			is_updated = false;
			for (int i = 0; i < N; i++) {
				for (int j = N-2; j >=0; j--) {	//오른쪽에서 두번째부터 왼쪽으로
					if (graph[i][j] == 0)continue;

					int cur, next;
					cur = graph[i][j];
					next = graph[i][j+1];

					if (next == 0) {
						graph[i][j] = 0;
						graph[i][j+1] = cur;
						is_updated = true;
					}
					else if (cur == next) {
						if (visited[i][j+1] == 1)continue;	//한큐에한번만 합칠수있음.
						graph[i][j] = 0;
						graph[i][j+1] = cur + next;
						visited[i][j+1] = 1;
						is_updated = true;
					}
				}
			}
		}
	}
	//print();

	//계산
	if (count == 5) {
		int candi = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] > candi) {
					candi = graph[i][j];
				}
			}
		}
		if (answer < candi) {
			answer = candi;
		}

		return;
		
	}

	//재귀
	else {
		for (int d = 0; d < 4; d++) {
			int temp[21][21];
			
			//save
			backup(graph, temp);
			//dfs
			dfs(d, count + 1);
			//load
			backup(temp, graph);

		}
	}

}

void backup(int from[21][21], int to[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			to[i][j] = from[i][j];
		}
	}
}

void print()
{
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	system("pause");
}