#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int dx[] = { 0,0,-1,+1 };
int dy[] = { -1,+1,0,0 };

bool is_visited[26][26] = { false, };
int nation_graph[26][26] = { 0, };
int graph[26][26] = { 0, };

typedef struct pos {
	int y;
	int x;
}pos;
int bfs(pos node);
int nation = 0;
int N;

vector<int> nation_cnt;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_visited[i][j] == true)continue;
			if (graph[i][j] == 0) {
				is_visited[i][j] = true;
				continue;
			}
			if (graph[i][j] == 1 && is_visited[i][j] == false) {
				nation++;
				nation_cnt.push_back(bfs({ i,j }));
			}
		}
	}

	cout << nation_cnt.size() << endl;
	sort(nation_cnt.begin(), nation_cnt.end());
	
	for (int i = 0; i < nation_cnt.size(); i++) {
		cout << nation_cnt[i] << endl;
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << nation_graph[i][j] << " ";
		}
		cout << endl;
	}*/
	
}

int bfs(pos node) {
	int count = 0;

	queue<pos> q;
	q.push(node);

	while (!q.empty()) {
		pos cur = q.front();
		nation_graph[cur.y][cur.x] = nation;
		count++;
		q.pop();

		for (int d = 0; d < 4; d++) {
			pos next;
			next.x = cur.x + dx[d];
			next.y = cur.y + dy[d];

			if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N)continue;
			if (is_visited[next.y][next.x] == true)continue;
			if (graph[next.y][next.x] == 0)continue;

			q.push({ next });
			is_visited[next.y][next.x] = true;
		}
	}
	if (count == 1)return 1;
	return count-1;
}