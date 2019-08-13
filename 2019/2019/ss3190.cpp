/*****************
https://www.acmicpc.net/problem/3190
��
N*N �׷���
�ʴ� ���� �̵�
������++; �Ӹ��� ����ĭ
����� ������ ������ �״��
����� ������ ������--;

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
int N; //�׷��� ũ��
int K; //��� ����
int L; //���� ���⺯ȯ Ƚ��
int X; //X�� ���Ŀ� ���� C�� ������ȯ
char C; //L����, D������ ȸ��
int graph[101][101] = { 0, };
queue<pos> snake;
queue<rot> change;
int snake_dir;	//���� ���� ��0 ��1 ��2 ��3
pos snake_head;
int answer = 0;

int main()
{
	scanf("%d %d",&N,&K);

	//��� K�� ��ġ
	for (int i = 0; i < K; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		graph[y-1][x-1] = 1;	//1 ���
	}
	
	//������ȯ ���
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &X, &C);
		rot temp;
		temp.time = X; temp.dir = C;
		change.push(temp);
	}

	//�� �ʱ�ȭ
	snake.push({ 0,0 });
	snake_dir = 0;//��
	snake_head = { 0,0 };

	while (move()==true) {
		answer++;
		
		if (!change.empty()) {
			if (answer == change.front().time) {
				//������ȯ
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

	if (snake_dir == 0) {	//��
		snake_head.x++;
	}
	else if (snake_dir == 1) {	//��
		snake_head.y++;
	}
	else if (snake_dir == 2) {	//��
		snake_head.x--;
	}
	else if (snake_dir == 3) {	//��
		snake_head.y--;
	}
	
	//������ ����
	snake.push(snake_head);

	//����� �ִٸ�
	if (graph[snake_head.y][snake_head.x] == 1) {
		apple = true;
	}
	//����� ������
	else if (graph[snake_head.y][snake_head.x] == 0) {
		apple = false;
		tail.y = snake.front().y; tail.x = snake.front().x;
		//���� ����
		snake.pop();
	}
	
	//���� ���� üũ
	if (graph[snake_head.y][snake_head.x]==2 ||snake_head.x < 0 || snake_head.x >= N || snake_head.y < 0 || snake_head.y >= N) {
		return false;
	}

	if (apple == false) {
		graph[tail.y][tail.x] = 0;
	}
	graph[snake_head.y][snake_head.x] = 2;

	return true;
}