/************
연구소
N*M graph
빈칸 0, 벽 1, 바이러스 2,

************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef struct pos {
	int y;
	int x;
}pos;


//global var
int N, M;
int graph[9][9];
vector<pos> virus;
int dx[] = { -1,+1,0,0 };
int dy[] = { 0,0,-1,+1 };
int answer = -1;

//func
void dfs(pos cur_pos, int count);
void print();
void graph_backup(int from[9][9], int to[9][9]);
void virus_check();

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2) {
				virus.push_back({ i,j });	//바이러스 위치
			}
			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				pos cur_pos = { i,j };
				graph[i][j] = 1;
				dfs(cur_pos, 1);
				graph[i][j] = 0;
			}
		}
	}

	printf("%d\n", answer);

}

void dfs(pos cur_pos, int count) {
	
	//print();
	//system("pause");
	if (count == 3) {
		int backup[9][9];
		graph_backup(graph, backup);
		virus_check();
		graph_backup(backup, graph);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				pos next_pos = { i,j };
				graph[i][j] = 1;
				dfs(next_pos, count + 1);
				graph[i][j] = 0;
			}
		}
	}
}

void print() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

void virus_check() {
	
	bool is_visited[9][9] = { false, };
	for (int i = 0; i < virus.size(); i++) {
		queue<pos> q;
		q.push({ virus[i].y, virus[i].x });

		while (!q.empty()) {
			pos cur_virus_node = q.front();
			q.pop();

			for (int d = 0; d < 4; d++) {
				pos next = { cur_virus_node.y + dy[d], cur_virus_node.x + dx[d] };
				
				if (is_visited[next.y][next.x] == true) continue;
				if (graph[next.y][next.x] == 1)continue;
				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)continue;
				
				is_visited[next.y][next.x] = true;
				graph[next.y][next.x] = 2;
				q.push(next);
			}
		}
		
	}

	//print();

	int candi = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				candi++;
			}
		}
	}

	if (answer < candi) {
		answer = candi;
	}
}

void graph_backup(int from[9][9], int to[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			to[i][j] = from[i][j];
		}
	}
}