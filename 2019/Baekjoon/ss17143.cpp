/*****
낚시왕
https://www.acmicpc.net/problem/17143
R*C graph
칸마다 상어가 들어있음
1. 낚시왕이 오른쪽으로 이동
2. 열에서 땅에 가장 가까운 상어를 잡는다
3. 상어가 이동한다.
3-1. 경계에 다다르면 방향을 바꿔서 나머지를 이동한다.
4. 한 칸에 상어가 두마리 이상일 경우 큰 상어가 다 잡아먹는다.
input : R, C(2~100), 상어 수M(0~R*C)
		상어정보 : r,c(위치),s(속력),d(이동방향1위2아3오4왼),z(크기)
output : 낚시왕이 잡은 상어 크기의 합

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
	int s;	//속력
	int d;	//방향 1위2아3오4왼
	int z;	//크기
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

	//상어 성분 입력
	for (int i = 0; i < M; i++) {
		SHARK temp;
		cin >> temp.r >> temp.c >> temp.s >> temp.d >> temp.z;
		//상어 성분 저장
		sharks.push_back(temp);
		//그래프에 상어위치를 저장
		graph[temp.r][temp.c] = i;
	}
	
	for (kingPos = 1; kingPos <= C; kingPos++) {
		//가장 가까운 상어 탐색
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

			//상어 낚시
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

		
		//상어 이동
		for (int curShark = 0; curShark < sharks.size(); curShark++) {
			//이동
			for (int speed = 0; speed < sharks[curShark].s; speed++) {
				int next_y, next_x, cur_d;
				cur_d = sharks[curShark].d;
				next_y = sharks[curShark].r + dy[sharks[curShark].d - 1];
				next_x = sharks[curShark].c + dx[sharks[curShark].d - 1];

				if (next_x <= 0 && cur_d==4) {
					//d가 왼쪽일경우
					sharks[curShark].d = 3;	//오른쪽으로
				}
				else if (next_x >= C && cur_d == 3) {
					//d가 오른쪽일경우
					sharks[curShark].d = 4;	//왼쪽으로
				}
				else if (next_y <= 0 && cur_d == 1) {
					//위일경우
					sharks[curShark].d = 2;
				}
				else if (next_y >= R && cur_d == 2) {
					//아래일경우
					sharks[curShark].d = 1;
				}

				//이동
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