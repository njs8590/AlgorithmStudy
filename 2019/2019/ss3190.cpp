/*****************
https://www.acmicpc.net/problem/3190
뱀
N*N 그래프
초당 뱀이 이동
몸길이++; 머리를 다음칸
사과가 있으면 몸길이 그대로
사과가 없으면 몸길이--;

*****************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//type
typedef struct pos {
	int y;
	int x;
}pos;
typedef struct rot {
	int time;
	char dir;
}rot;

//func
bool move();

//global var
int N; //그래프 크기
int K; //사과 개수
int L; //뱀의 방향변환 횟수
int X; //X초 이후에 뱀이 C로 방향전환
char C; //L왼쪽, D오른쪽 회전
int graph[101][101] = { 0, };
queue<pos> snake;
queue<rot> change;
int snake_dir;	//뱀의 방향 우0 하1 좌2 상3
pos snake_head;
int answer = 0;

int main()
{
	scanf("%d %d",&N,&K);

	//사과 K개 배치
	for (int i = 0; i < K; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		graph[y-1][x-1] = 1;	//1 사과
	}
	
	//방향전환 기록
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &X, &C);
		rot temp;
		temp.time = X; temp.dir = C;
		change.push(temp);
	}

	//뱀 초기화
	snake.push({ 0,0 });
	snake_dir = 0;//우
	snake_head = { 0,0 };

	while (move()==true) {
		answer++;
		
		if (!change.empty()) {
			if (answer == change.front().time) {
				//방향전환
				if (change.front().dir == 'D') {
					snake_dir = (snake_dir + 1) % 4;	//0123
				}
				else if (change.front().dir == 'L') {
					snake_dir = (snake_dir + 3) % 4;	//0321
				}
				change.pop();
			}
		}
		
	}

	printf("%d\n", answer+1);
}

bool move()
{
	pos temp;
	pos tail;
	bool apple;

	if (snake_dir == 0) {	//우
		snake_head.x++;
	}
	else if (snake_dir == 1) {	//하
		snake_head.y++;
	}
	else if (snake_dir == 2) {	//좌
		snake_head.x--;
	}
	else if (snake_dir == 3) {	//상
		snake_head.y--;
	}
	
	//몸길이 증가
	snake.push(snake_head);

	//사과가 있다면
	if (graph[snake_head.y][snake_head.x] == 1) {
		apple = true;
	}
	//사과가 없으면
	else if (graph[snake_head.y][snake_head.x] == 0) {
		apple = false;
		tail.y = snake.front().y; tail.x = snake.front().x;
		//꼬리 삭제
		snake.pop();
	}
	
	//게임 종료 체크
	if (graph[snake_head.y][snake_head.x]==2 ||snake_head.x < 0 || snake_head.x >= N || snake_head.y < 0 || snake_head.y >= N) {
		return false;
	}

	if (apple == false) {
		graph[tail.y][tail.x] = 0;
	}
	graph[snake_head.y][snake_head.x] = 2;

	return true;
}