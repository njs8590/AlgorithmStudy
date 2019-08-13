/*****
graph size = N * N
물고기 M마리
아기상어 1마리 - 처음 크기 2
한칸에 물고기 최대 1마리
조건1) 자기보다 큰 물고기는 지나갈 수 없음.
조건2) 자기보다 작은 물고기만 먹을 수 있음.
		= 크기가 같은 물고기는 먹을 수 없지만 지나갈 순 있음.
조건3) 가장가까운 물고기를 먹는다
조건4) 거리가 같은 물고기가 많다면 -> 가장왼쪽 위의 물고기를 먹는다.
조건5) 자기 크기만큼 물고기를 먹으면 레벨업
종료) 더이상 먹을 물고기가 없으면 종료!

input)
N 그래프 크기
공간 상태. 0= 빈칸, 1~6 = 물고기 크기, 9 = 아기상어

*****/

#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int N;
int graph[20][20];

void print();

typedef struct pos {
	int y;
	int x;
	int time;
};

pos shark_pos;
int shark_size = 2;
int shark_eat = 0;


int dx[] = { 0,-1,+1,0 };
int dy[] = { -1,0,0,+1 };	//위왼오아

int main()
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 9) {
				shark_pos = { i,j,0 };	//상어의 위치
				graph[i][j] = 0;
			}
			
		}
	}

	bool is_update = true;

	while (is_update) {
		is_update = false;
		
		queue<pos> q;
		q.push(shark_pos);

		bool find_eating = false;
		bool is_visited[20][20] = { false, };
		//is_visited[shark_pos.y][shark_pos.x] = true;	//현재 상어위치
		
		pos candi_pos;	//잡아먹을 물고기

		while (!q.empty()) {
			pos cur_pos = q.front();
			q.pop();

			//처음 먹을 물고기를 발견한 이후
			//시간기준으로 같은시간이면 큐에 다 넣고, 비교해서 candi를 정함.
			if (find_eating == true&&graph[cur_pos.y][cur_pos.x]!=0&&graph[cur_pos.y][cur_pos.x]<shark_size) {
				if (cur_pos.time > candi_pos.time)continue;	//물고기를 발견했는데, 이후 시간을 계속 탐색하려 하면 continue
				
				if (cur_pos.y < candi_pos.y) {	//더 위에있으면
					candi_pos = cur_pos;
				}
				else if (cur_pos.y == candi_pos.y && cur_pos.x < candi_pos.x) {	//같은 높이인데, 더 왼쪽에있으면
					candi_pos = cur_pos;
				}
			}

			if (graph[cur_pos.y][cur_pos.x]!=0 && graph[cur_pos.y][cur_pos.x] < shark_size && find_eating==false) {
				//물고기다 && 먹을수있따 && 처음 찾은것이다.
				find_eating = true;
				candi_pos = cur_pos;
				is_update = true;	//물고기를 잡아먹을 수 있다.
				continue;
			}

			//이동할 때마다 시간계산
			//4방향 탐색하고 큐에넣음
			//일단 다 탐색하고 먹을 수 있는애 중 조건4를 만족하는 애를 먹음.
			//다시 큐 진행
			
			for (int d = 0; d < 4; d++) {
				pos next;
				next.x = cur_pos.x + dx[d];
				next.y = cur_pos.y + dy[d];
				next.time = cur_pos.time + 1;	//다음칸은 현재칸보다 하나 증가한 시간
				
				if (next.x >= N || next.x < 0 || next.y >= N || next.y < 0)continue;//맵 밖은 갈 수 없음
				if (graph[next.y][next.x] > shark_size) continue; //물고기가 상어보다 크면 갈 수 없음
				if (is_visited[next.y][next.x] == true) continue;

				//system("pause");

				is_visited[next.y][next.x] = true;
				q.push(next);
			}
			
		}

		//candi_pos 를 잡아먹으면 됨.
		if (is_update) {
			//cout << "크앙" << endl;
			//cout << candi_pos.y << "," << candi_pos.x << "," << candi_pos.time << endl;
			graph[candi_pos.y][candi_pos.x] = 0;
			shark_eat++;
			if (shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
			shark_pos = candi_pos;

		}

	}

	printf("%d\n", shark_pos.time);
	
}

void print()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}