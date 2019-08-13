/**************
https://www.acmicpc.net/problem/14500
��Ʈ�ι̳�
N * M �׷���
4ĭ�� �̾���� ��Ʈ�ι̳� ���� 5��
ȸ��, ��Ī ����
�ϳ��� ������ ���Ƽ� ���� ĭ�� ���� ���� �ִ��� ���� ���ϸ� �ȴ�.

**************/

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

//func
void dfs(pos node, int type);
bool valid_check(pos cur1, pos cur2, pos cur3, pos cur4);
int res(pos cur1, pos cur2, pos cur3, pos cur4);
void answer_check(pos cur1, pos cur2, pos cur3, pos cur4);

//global var
int N, M; //i, j
int graph[501][501];
int answer = 0;


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			pos node;
			node.y = i; node.x = j;

			for (int type = 0; type < 5; type++) {
				
				dfs(node, type);

			}
			
		}
	}

	printf("%d\n", answer);

	return 0;
}

void dfs(pos node, int type) {

	if (type == 0) {	//----
		
		pos cur1, cur2, cur3, cur4;
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.x += 1; 
		cur3.x += 2; 
		cur4.x += 3;
		answer_check(cur1, cur2, cur3, cur4);
		
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; 
		cur3.y += 2; 
		cur4.y += 3;
		answer_check(cur1, cur2, cur3, cur4);
		
	}
	else if (type == 1) {	//��

		pos cur1, cur2, cur3, cur4;
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.x += 1; 
		cur3.y += 1; 
		cur4.x += 1; cur4.y += 1;
		answer_check(cur1, cur2, cur3, cur4);
		
	}
	else if (type == 2) {	//��

		pos cur1, cur2, cur3, cur4;
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; cur2.x += 0;
		cur3.y += 2; cur3.x += 0;
		cur4.y += 2; cur4.x += 1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += -1;
		cur3.y += 0; cur3.x += -2;
		cur4.y += 1; cur4.x += -2;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += -1; cur2.x += 0;
		cur3.y += -2; cur3.x += 0;
		cur4.y += -2; cur4.x += -1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += 1;
		cur3.y += 0; cur3.x += 2;
		cur4.y += -1; cur4.x += 2;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; cur2.x += 0;
		cur3.y += 2; cur3.x += 0;
		cur4.y += 2; cur4.x += -1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += -1;
		cur3.y += 0; cur3.x += -2;
		cur4.y += -1; cur4.x += -2;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += -1; cur2.x += 0;
		cur3.y += -2; cur3.x += 0;
		cur4.y += -2; cur4.x += 1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += 1;
		cur3.y += 0; cur3.x += 2;
		cur4.y += 1; cur4.x += 2;
		answer_check(cur1, cur2, cur3, cur4);

	}

	else if (type == 3) {	//-��
		pos cur1, cur2, cur3, cur4;
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; cur2.x += 0;
		cur3.y += 1; cur3.x += 1;
		cur4.y += 2; cur4.x += 1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += -1;
		cur3.y += 1; cur3.x += -1;
		cur4.y += 1; cur4.x += -2;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; cur2.x += 0;
		cur3.y += 1; cur3.x += -1;
		cur4.y += 2; cur4.x += -1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += 1;
		cur3.y += 1; cur3.x += 1;
		cur4.y += 1; cur4.x += 2;
		answer_check(cur1, cur2, cur3, cur4);

	}

	else if (type == 4) {	//��
		pos cur1, cur2, cur3, cur4;
		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += 1;
		cur3.y += 0; cur3.x += 2;
		cur4.y += 1; cur4.x += 1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 1; cur2.x += 0;
		cur3.y += 2; cur3.x += 0;
		cur4.y += 1; cur4.x += -1;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += 0; cur2.x += -1;
		cur3.y += -1; cur3.x += -1;
		cur4.y += 0; cur4.x += -2;
		answer_check(cur1, cur2, cur3, cur4);

		cur1 = cur2 = cur3 = cur4 = node;
		cur2.y += -1; cur2.x += 0;
		cur3.y += -1; cur3.x += 1;
		cur4.y += -2; cur4.x += 0;
		answer_check(cur1, cur2, cur3, cur4);
	}

}

bool valid_check(pos cur1, pos cur2, pos cur3, pos cur4) {
	
	if (cur1.x < 0 || cur1.x >= M || cur1.y < 0 || cur1.y >= N) return false;
	if (cur2.x < 0 || cur2.x >= M || cur2.y < 0 || cur2.y >= N) return false;
	if (cur3.x < 0 || cur3.x >= M || cur3.y < 0 || cur3.y >= N) return false;
	if (cur4.x < 0 || cur4.x >= M || cur4.y < 0 || cur4.y >= N) return false;

	return true;
}

int res(pos cur1, pos cur2, pos cur3, pos cur4) {
	int candi = 0;
	
	candi += graph[cur1.y][cur1.x];
	candi += graph[cur2.y][cur2.x];
	candi += graph[cur3.y][cur3.x];
	candi += graph[cur4.y][cur4.x];

	return candi;
}

void answer_check(pos cur1, pos cur2, pos cur3, pos cur4) {
	int candi = 0;

	if (valid_check(cur1, cur2, cur3, cur4) == true) {
		candi = res(cur1, cur2, cur3, cur4);
		if (answer < candi) {

			//printf("%d,%d / %d,%d / %d,%d / %d,%d \n", cur1.y, cur1.x, cur2.y, cur2.x, cur3.y, cur3.x, cur4.y, cur4.x);
			answer = candi;
		}
	}
}