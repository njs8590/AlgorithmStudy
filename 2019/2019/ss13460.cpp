/**************
구슬탈출
Red, Blue 한개씩 graph에 넣고, Red를 구멍을 통해 빼내는 게임
세로 N = i;
가로 M = j;
가장 바깥 행과 열은 모두 막힘
보드에는 구멍이 한개
Blue가 구멍에 들어가면 안됨.
상하좌우로 기울이기만 가능.
각각의 공은 동시에 움직임. Blue가 들어가면 실패.
Red, Blue 동시에 들어가도 실패.
동시에 같은칸에 있을 수 없음. 더이상 구슬이 안움직이면 종료.
최소 몇번만에 Red를 빼낼 수 있는지?
10을 넘어가면 -1 출력
빈칸 ., 벽#, 구멍o, 구슬R, B

**************/

#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

//type
typedef struct pos {
	int y;
	int x;
}pos;
typedef struct R_B {
	pos R;
	pos B;
	int time;
}R_B;

int dx[] = { 0,0,-1,+1 };
int dy[] = { -1,+1,0,0 };

//variable
int N, M;
char graph[11][11];
pos R, B, O;
int answer = 11;
bool is_updated = false;

//func

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'R') {
				R = { i,j };
			}
			else if (graph[i][j] == 'B') {
				B = { i,j };
			}
			else if (graph[i][j] == 'O') {
				O = { i,j };
			}
		}
	}

	queue<R_B> q;
	q.push({ R, B, 1 });

	while (!q.empty()) {
		pos cur_R, cur_B;
		int time;
		cur_R = q.front().R;
		cur_B = q.front().B;
		time = q.front().time;
		q.pop();
		
		//R이 구멍을 찾으면
		

		for (int d = 0; d < 4; d++) {//4방향
			pos next_R, next_B;
			next_R = cur_R;
			next_B = cur_B;


			bool find_answer = false;
			bool find_check = false;

			while (true) {
				next_R.y += dy[d]; next_R.x += dx[d];
				next_B.y += dy[d]; next_B.x += dx[d];

				//둘다 벽을 만날 때 까지 굴러감.
				if (graph[next_R.y][next_R.x] == '#'&&graph[next_B.y][next_B.x] == '#') {
					next_R.y -= dy[d]; next_R.x -= dx[d];
					next_B.y -= dy[d]; next_B.x -= dx[d];
					break;
				}
				//R만 벽
				else if (graph[next_R.y][next_R.x] == '#') {
					//리턴
					next_R.y -= dy[d]; next_R.x -= dx[d];
					//B랑 위치가 같아지면 B도 리턴, break
					if (next_R.y == next_B.y&&next_R.x == next_B.x) {
						next_B.y -= dy[d]; next_B.x -= dx[d];
						break;
					}
				}
				//B만 벽
				else if (graph[next_B.y][next_B.x] == '#') {
					next_B.y -= dy[d]; next_B.x -= dx[d];
					//R도 리턴, break;
					if (next_R.y == next_B.y&&next_R.x == next_B.x) {
						next_R.y -= dy[d]; next_R.x -= dx[d];
						break;
					}
				}

				//R이 구멍으로
				if (next_R.y == O.y && next_R.x == O.x) {
					//cout << "find!!!!!" << endl;
					find_answer = true;
					find_check = true;
				}
				//B가 구멍으로
				if (next_B.y == O.y && next_B.x == O.x) {
					//cout << "no....." << endl;
					find_answer = false;
					find_check = true;
					break;
				}
			}

			if (find_answer == true) {
				
				if (answer > time) {
					//cout << "update!!!!!!!!!!!!!!" << endl;
					answer = time;
					//cout << answer;
				}
				break;
			}
			
			if(find_check==false){
				if(next_R.y!=cur_R.y|| next_R.x != cur_R.x|| next_B.y != cur_B.y|| next_B.x != cur_B.x)
					q.push({ next_R, next_B, time + 1 });
			}
					
		}//4방향종료
		
		if (time == 10) {
			break;
		}
	}

	if (answer>10) {
		answer = -1;
	}
	printf("%d\n", answer);
	
}
