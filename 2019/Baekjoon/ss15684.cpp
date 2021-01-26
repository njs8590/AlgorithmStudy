#include<iostream>
#include<stdio.h>

using namespace std;

int N, M, H;

typedef struct pos {
	int y;
	int x;
}pos;

int graph[31][11] = { 0, };

int answer = 0;

void dfs(int y, int x, int garo_count);
bool start();
void print();

int main()
{
	cin >> N >> M >> H;
	//세로줄>>그릴가로줄>>가로줄
	for (int m = 0; m < M; m++) {//가로선 입력받기
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;	//a행 연결
		graph[a][b + 1] = 1;
	}
	
	if (start()) {
		//안그려도 답임
	}
	else {
		dfs(0,0,1);
	}

	cout << answer << endl;
	//print();

	return 0;
}

void dfs(int y, int x, int garo_count) {
	//그려
	if (garo_count == 4) {
		return;
	}

	graph[y][x] = 1;
	graph[y][x + 1] = 1;
	//cout << garo_count << endl;
	print();
	
	//돌려
	//cout << answer << endl;
	if (start() == true) {
		//cout << garo_count << endl;
		answer = garo_count;
		return;
	}

	if(garo_count<3){
		//한번씩 다 node로 삼아야됨
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j < N; j++) {
				//그릴수있는가?
				//오 그려져잇으면 패스
				if (graph[i][j] == 0 && graph[i][j + 1] == 0) {
					if (graph[i][j + 2] == 1)continue;
					//if (graph[i][j - 1] == 1)continue;
					dfs(i, j, garo_count + 1);
				}

			}
		}
	}

	//backup
	graph[y][x] = 0;
	graph[y][x + 1] = 0;

	return;

}

void print()
{
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool start() {
	for (int node = 1; node < N; node++) {
		pos cur;
		cur.x = node;
		cur.y = 0;

		while (cur.y <= H) {
			if (graph[cur.y][cur.x] == 1) {	//내려가다 1만남
				if (graph[cur.y][cur.x + 1] == 1) {
					//오른쪽으로
					cur.x++;
				}
				else if (graph[cur.y][cur.x - 1] == 1) {
					//왼쪽으로
					cur.x--;
				}
			}
			//한칸아래로
			cur.y++;
		}
		if (cur.y != node) {
			return false;
		}
	}

	return true;
	
}