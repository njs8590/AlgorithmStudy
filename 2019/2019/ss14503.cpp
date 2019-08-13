/*******************
https://www.acmicpc.net/problem/14503
로봇 청소기
그래프 N * M
i = N, j = M
로봇좌표 (r, c)
바라보는 방향 북0, 동1, 남2, 서3

*******************/


#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct pos {
	int y;
	int x;
}pos;

void print();

pos R_pos;	//로봇의 위치
int N, M;	//i,j
int graph[51][51];
int R_dir = 0;	//로봇이 바라보는 방향
//북0, 동1, 남2, 서3

//현재방향의 왼쪽
int dx[] = { -1,0,+1,0};
int dy[] = { 0,-1,0,+1};

//후진하는 방향
int rdx[] = {0,-1,0,+1};
int rdy[] = {+1,0,-1,0};

int answer = 0;

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &R_pos.y, &R_pos.x, &R_dir);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	//청소
	graph[R_pos.y][R_pos.x] = 2;
	answer++;

	bool can_back=true;
	

	while (can_back) {

		int count = 0;
		bool can_clean = false;

		while (count < 4&&can_clean==false) {
			
			count++;

			pos next;//현재바라보는 방향의 왼쪽
			next.y = R_pos.y + dy[R_dir]; next.x = R_pos.x + dx[R_dir];

			if (graph[next.y][next.x] == 0) {//왼쪽이 청소가 안되었다.
				//회전
				R_dir = (R_dir + 3) % 4;
				//전진
				R_pos = next;
				//청소
				graph[R_pos.y][R_pos.x] = 2;
				can_clean = true;
				answer++;
			}

			if (can_clean == false) {
				//회전
				R_dir = (R_dir + 3) % 4;
			}
			
		}//while 종료

		//청소할 곳이 없다면
		if (can_clean == false) {
			//후진
			pos next;
			next.y = R_pos.y + rdy[R_dir]; next.x = R_pos.x + rdx[R_dir];
			//후진할 곳이 벽이라면
			if (graph[next.y][next.x] == 1) {
				can_back = false;
			}
			else if (graph[next.y][next.x] == 2 || graph[next.y][next.x] == 0) {
				R_pos = next;
				can_back = true;
			}
		}

	}

	printf("%d\n", answer);
		
}