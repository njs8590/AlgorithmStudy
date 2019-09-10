/*****
���ÿ�
https://www.acmicpc.net/problem/17143
R*C graph
ĭ���� �� �������
1. ���ÿ��� ���������� �̵�
2. ������ ���� ���� ����� �� ��´�
3. �� �̵��Ѵ�.
3-1. ��迡 �ٴٸ��� ������ �ٲ㼭 �������� �̵��Ѵ�.
4. �� ĭ�� �� �θ��� �̻��� ��� ū �� �� ��ƸԴ´�.
input : R, C(2~100), ��� ��M(0~R*C)
		������� : r,c(��ġ),s(�ӷ�),d(�̵�����1��2��3��4��),z(ũ��)
output : ���ÿ��� ���� ��� ũ���� ��

*****/

#define MAX 200

#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>

using namespace std;

//typedef
typedef struct SHARK {
	int r;	//y
	int c;	//x
	int s;	//�ӷ�
	int d;	//���� 1��2��3��4��
	int z;	//ũ��
}SHARK;

//global var
int R, C, M;
int graph[MAX][MAX];
vector<SHARK> sharks;
int kingPos = -1;
int answer = 0;
int dx[] = {0,0,+1,-1};
int dy[] = { -1,+1,0,0 };

void init();
void init() {
	//init
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			graph[i][j] = -1;
		}
	}
}

int main(void) {

	
	cin >> R >> C >> M;
	
	init();

	//��� ���� �Է�
	for (int i = 0; i < M; i++) {
		SHARK temp;
		cin >> temp.r >> temp.c >> temp.s >> temp.d >> temp.z;
		//��� ���� ����
		sharks.push_back(temp);
		//�׷����� �����ġ�� ����
		graph[temp.r][temp.c] = i;
	}
	
	for (kingPos = 1; kingPos <= C; kingPos++) {
		//���� ����� ��� Ž��
		int y=0;

		
		/*
		cout << kingPos << endl;
		
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) {
				if (graph[i][j] == -1)cout << "- ";
				else cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		while (graph[y][kingPos] == -1 && y<R) {
			y++;
		}
		int nearShark = graph[y][kingPos];

		if (nearShark != -1) {
			//cout << "eat" << sharks[nearShark].z << endl;

			//��� ����
			answer += sharks[nearShark].z;
			sharks.erase(sharks.begin() + nearShark);
		}


		/*
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) {
				if (graph[i][j] == -1)cout << "- ";
				else cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		
		//��� �̵�
		for (int curShark = 0; curShark < sharks.size(); curShark++) {
			//�̵�
			for (int speed = 0; speed < sharks[curShark].s; speed++) {
				int next_y, next_x, cur_d;
				cur_d = sharks[curShark].d;
				next_y = sharks[curShark].r + dy[sharks[curShark].d - 1];
				next_x = sharks[curShark].c + dx[sharks[curShark].d - 1];

				if (next_x <= 0 && cur_d==4) {
					//d�� �����ϰ��
					sharks[curShark].d = 3;	//����������
				}
				else if (next_x >= C && cur_d == 3) {
					//d�� �������ϰ��
					sharks[curShark].d = 4;	//��������
				}
				else if (next_y <= 0 && cur_d == 1) {
					//���ϰ��
					sharks[curShark].d = 2;
				}
				else if (next_y >= R && cur_d == 2) {
					//�Ʒ��ϰ��
					sharks[curShark].d = 1;
				}

				//�̵�
				sharks[curShark].r += dy[sharks[curShark].d - 1];
				sharks[curShark].c += dx[sharks[curShark].d - 1];
			}
		}
		/*
		cout << endl;

		for (int i = 0; i < sharks.size(); i++) {
			cout << sharks[i].z;
		}
		cout << endl;
		*/

		init();

		vector<int> eraseList;

		for (int curShark = 0; curShark < sharks.size(); curShark++) {

			int y = sharks[curShark].r;
			int x = sharks[curShark].c;
			int size = sharks[curShark].z;

			if (graph[y][x] == -1) {
				graph[y][x] = curShark;
			}
			else if (sharks[graph[y][x]].z > size) {
				//cout << "erase" << sharks[curShark].z << endl;
				eraseList.push_back(curShark);
				//sharks.erase(sharks.begin() + curShark);
				
			}
			else if (sharks[graph[y][x]].z < size) {
				//cout << "erase" << sharks[curShark].z << endl;
				eraseList.push_back(graph[y][x]);
				//sharks.erase(sharks.begin() + graph[y][x]);
				graph[y][x] = curShark;

			}
		}
		for (int i = 0; i < eraseList.size(); i++) {
			sharks.erase(sharks.begin() + eraseList[i]);
		}
		
	}

	cout << answer << endl;

	return 0;
}