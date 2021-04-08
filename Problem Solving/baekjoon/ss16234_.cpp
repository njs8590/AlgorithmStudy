#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

void print();
void print2();

typedef struct graph {
	int value;
	int nation;
}graph;

typedef struct pos {
	int y;
	int x;
}pos;

typedef struct sum_count {
	int sum = 0;
	int count = 0;
}sum_count;

int N; //배열 NxN
int L, R; //인구차이 L이상 R 이하

graph A[50][50];

//4방향
int dx[] = { 0,0,-1,+1 };
int dy[] = { -1,+1,0,0 };

int answer = -1;

int main()
{
	//input
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j].value;
		}
	}
	
	bool is_update = true;

	while (is_update == true) {
		is_update = false;
		answer++;

		bool is_visited[50][50] = { false, };
		//완전탐색하면서 nation 분류
		//bfs 방식으로
		int cur_nation_num = 0;

		sum_count sumcnt[2501];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (is_visited[i][j] == true) { continue; }

				queue<pos> q;
				q.push({ i,j });
				A[i][j].nation = ++cur_nation_num;
				is_visited[i][j] = true;	//node가 된 적이 있음.
				
				//print();
				while (!q.empty()) {
					pos cur = q.front();
					q.pop();
					//인구수누적 + 국경open 수 누적
					A[cur.y][cur.x].nation = cur_nation_num;
					sumcnt[cur_nation_num].sum += A[cur.y][cur.x].value;
					//cout << cur.y << " " << cur.x << endl;
					sumcnt[cur_nation_num].count++;

					//node 기준으로 4방향 탐색
					for (int d = 0; d < 4; d++) {
						pos next;
						next.y = cur.y + dy[d];
						next.x = cur.x + dx[d];

						if (next.y < 0 || next.y >= N || next.x < 0 || next.x>= N) { continue; }//맵을벗어남
						if (is_visited[next.y][next.x] == true) { continue; }//방문된적이 있음
						//조건 만족한다면 push
						//조건 1 : 차이가 L이상 R이하
						int diff;
						diff = abs(A[cur.y][cur.x].value - A[next.y][next.x].value);
						if (L <= diff && diff <= R) {
							q.push(next);
							is_visited[next.y][next.x] = true;
							//new 군집 발생
							is_update = true;
						}
					}
				}

			}
		}

		//인구 이동
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j].value = sumcnt[A[i][j].nation].sum / sumcnt[A[i][j].nation].count;
				//A초기화
				A[i][j].nation = 0;
			}
		}
		
		//print2();
	}//while_end
	
	cout << answer << endl;

	return 0;

}

void print()
{
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j].nation << " ";
		}
		cout << endl;
	}
}

void print2()
{
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j].value << " ";
		}
		cout << endl;
	}
}