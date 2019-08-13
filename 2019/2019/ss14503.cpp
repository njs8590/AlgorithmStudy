/*******************
https://www.acmicpc.net/problem/14503
�κ� û�ұ�
�׷��� N * M
i = N, j = M
�κ���ǥ (r, c)
�ٶ󺸴� ���� ��0, ��1, ��2, ��3

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

pos R_pos;	//�κ��� ��ġ
int N, M;	//i,j
int graph[51][51];
int R_dir = 0;	//�κ��� �ٶ󺸴� ����
//��0, ��1, ��2, ��3

//��������� ����
int dx[] = { -1,0,+1,0};
int dy[] = { 0,-1,0,+1};

//�����ϴ� ����
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
	
	//û��
	graph[R_pos.y][R_pos.x] = 2;
	answer++;

	bool can_back=true;
	

	while (can_back) {

		int count = 0;
		bool can_clean = false;

		while (count < 4&&can_clean==false) {
			
			count++;

			pos next;//����ٶ󺸴� ������ ����
			next.y = R_pos.y + dy[R_dir]; next.x = R_pos.x + dx[R_dir];

			if (graph[next.y][next.x] == 0) {//������ û�Ұ� �ȵǾ���.
				//ȸ��
				R_dir = (R_dir + 3) % 4;
				//����
				R_pos = next;
				//û��
				graph[R_pos.y][R_pos.x] = 2;
				can_clean = true;
				answer++;
			}

			if (can_clean == false) {
				//ȸ��
				R_dir = (R_dir + 3) % 4;
			}
			
		}//while ����

		//û���� ���� ���ٸ�
		if (can_clean == false) {
			//����
			pos next;
			next.y = R_pos.y + rdy[R_dir]; next.x = R_pos.x + rdx[R_dir];
			//������ ���� ���̶��
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