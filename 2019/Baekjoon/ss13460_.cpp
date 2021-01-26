/***************
https://www.acmicpc.net/problem/13460
구슬탈출
N * M 그래프
빨간구슬, 파란구슬
구멍으로 빨간구슬을 빼 내는 문제
파란구슬이 빠지면 실패, 빨간구슬 파란구슬 같이 빠져도 실패
상하좌우 기울이기만 가능
.빈칸, #벽, O구멍, R빨간구슬, B파란구슬
최소 몇 번 만에 빨간 구슬을 빼낼 수 있는지
10번 초과되면 -1을 출력

****************/


#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//struct
typedef struct pos {
	int y;
	int x;
}pos;
typedef struct qset {
	pos b;
	pos r;
	int dir;	//0123상하좌우
	int cnt;
};

//func

//global var
pos blue, red, hole;
int N, M;
char graph[11][11];
queue<qset> q;
int dx[4] = {0,0,-1,+1};
int dy[4] = {-1,+1,0,0};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//scanf("%1s", &graph[i][j]);
			cin >> graph[i][j];
			if (graph[i][j] == 'B') {
				blue.y = i; blue.x = j;
				graph[i][j] = '.';
			}
			if (graph[i][j] == 'R') {
				red.y = i; red.x = j;
				graph[i][j] = '.';
			}
			if (graph[i][j] == 'O') {
				hole.y = i; hole.x = j;
			}
		}
	}

	for (int d = 0; d < 4; d++) {
		q.push({ blue, red, d, 1 });
	}

	while (!q.empty()) {
		//printf("hi ");
		pos cur_blue, cur_red;
		int cur_dir, cur_cnt;
		cur_blue = q.front().b;
		cur_red = q.front().r;
		cur_dir = q.front().dir;
		cur_cnt = q.front().cnt;
		q.pop();

		//move
		bool move = true;
		bool blue_hole = false;
		bool red_hole = false;
		bool cannot_move = true;

		while (move == true) {

			move = false;
			pos next_blue, next_red;
			next_blue.y = cur_blue.y + dy[cur_dir]; next_blue.x = cur_blue.x + dx[cur_dir];
			next_red.y = cur_red.y + dy[cur_dir]; next_red.x = cur_red.x + dx[cur_dir];

			//blue
			if (graph[next_blue.y][next_blue.x] == '.') {

				if (next_blue.y == cur_red.y && next_blue.x == cur_red.x) {

				}
				else {
					//이동가능
					move = true;
					cannot_move = false;
					cur_blue = next_blue;
				}

			}
			else if (graph[next_blue.y][next_blue.x] == 'O') {
				blue_hole = true;
				move = true;
				cur_blue.y = -1; cur_blue.x = -1;
			}

			//red
			if (graph[next_red.y][next_red.x] == '.') {
				if (next_red.y == cur_blue.y && next_red.x == cur_blue.x) {

				}
				else {
					move = true;
					cannot_move = false;
					cur_red = next_red;
				}
			}
			else if (graph[next_red.y][next_red.x] == 'O') {
				red_hole = true;
				move = true;
				cur_red.y = -1; cur_red.x = -1;
			}
		}

		//check
		if (red_hole == true && blue_hole == false) {
			printf("%d\n", cur_cnt);
			//게임종료
			return 0;
		}
		if (blue_hole == false && cannot_move == false) {
			//push
			qset temp;
			temp.b = cur_blue;
			temp.r = cur_red;
			temp.cnt = cur_cnt + 1;
			if (temp.cnt < 11) {
				//printf("%d ", temp.cnt);
				for (int d = 0; d < 4; d++) {
					temp.dir = d;
					q.push(temp);
				}
			}
		}
	}

	int answer = -1;
	printf("%d\n", answer);
	return 0;
}