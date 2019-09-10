/*****
https://www.acmicpc.net/problem/17142
연구소3
바이러스 - 활성/비활성
연구소 N*N 그래프
빈칸0 , 벽1, 바이러스2
M개의 바이러스를 활성화 시켰을 때
그래프에 바이러스가 모두 퍼질 때 까지 걸리는 최소시간.
모두 퍼질 수 없으면 -1

*****/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

//struct
typedef struct pos {
	int y;
	int x;
	int time;
}pos;

//global var
int graph[51][51];	//그래프
int M;	//바이러스 갯수 1~10
int N;	//그래프 사이즈
vector<pos> virus;
bool isVirusChecked[10];
int test_graph[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int emptyCount;
int answer = 1000;

//function pre-defined
void dfs(int virusCount, int start);
void backup(int from[51][51], int to[51][51]);

int main(void) {

	emptyCount = 0;

	scanf("%d", &N);
	scanf("%d", &M);
	int zero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2) {
				pos temp;
				temp.y = i; temp.x = j; temp.time = 0;
				virus.push_back(temp);
				graph[i][j] = -2;
				emptyCount++;
			}
			else if (graph[i][j] == 1) {
				graph[i][j] = -1;
			}
			else {
				zero++;
				emptyCount++;
			}
		}
	}

	if (zero == 0) {
		answer = 0;
		cout << answer << endl;
		return 0;
	}
	queue<pos> emptyQ;
	dfs(0,0);

	if (answer == 1000) {
		answer = -1;
	}
	cout << answer << endl;

	return 0;
}


void dfs(int virusCount, int start) {
	int candi = 0;

	if (virusCount == M) {
		queue<pos> q;
		int emptyCount_local = emptyCount;
		bool isVisited[51][51];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				isVisited[i][j] = false;
			}
		}
		for (int i = 0; i < 10; i++) {
			if (isVirusChecked[i]) {
				pos temp;
				temp.y = virus[i].y; temp.x = virus[i].x; temp.time = 0;
				q.push(temp);
				isVisited[virus[i].y][virus[i].x] = true;
			}
		}
		backup(graph, test_graph);

		//spread
		bool find_answer = false;
		while (!q.empty()) {
			pos cur = q.front();
			if (candi < test_graph[cur.y][cur.x]) {
				candi = test_graph[cur.y][cur.x];
			}
			emptyCount_local--;
			if (emptyCount_local == 0) {
				find_answer = true;
				break;
			}
			q.pop();

			for (int d = 0; d < 4; d++) {
				pos next;
				next.x = cur.x + dx[d]; next.y = cur.y + dy[d]; next.time = cur.time + 1;

				if (isVisited[next.y][next.x]) continue;
				if (next.y >= N || next.y < 0)continue;
				if (next.x >= N || next.x < 0)continue;
				if (test_graph[next.y][next.x] == -1)continue;
				test_graph[next.y][next.x] = next.time;
				if (graph[next.y][next.x] == -2) {
					test_graph[next.y][next.x] = test_graph[cur.y][cur.x];
				}
				q.push(next);
				isVisited[next.y][next.x] = true;
			}
		}

		if (find_answer) {
			
			/*
			cout << "------------------" << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << test_graph[i][j] << " ";
				}
				cout << endl;
			}
			*/
			
			if (candi < answer) {
				answer = candi;
			}
			//answer update
		}
	}
	
	for (int i = start; i < virus.size(); i++) {
		if (isVirusChecked[i] == true)continue;
		pos curVirus = virus[i];
		isVirusChecked[i] = true;
		dfs(virusCount + 1, i);
		isVirusChecked[i] = false;
	}
}

void backup(int from[51][51], int to[51][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			to[i][j] = from[i][j];
		}
	}
}