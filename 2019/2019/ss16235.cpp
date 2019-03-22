#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>
#include<queue>

using namespace std;

void print();

typedef struct namoo {
	int yangboon;
	vector<int> namoo_info;
};
namoo graph[10][10];
int N, M, K;
int A[10][10];
int answer = 0;

//8방향
int dy[] = { -1,-1,-1,0,0,+1,+1,+1};
int dx[] = { -1,0,+1,-1,+1,-1,0,+1};

int main()
{
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];	//양분 입력
			graph[i][j].yangboon = 5;
		}
	}
	//초기나무위치 입력
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int r, c;
		r = x - 1; c = y - 1;
		graph[r][c].namoo_info.push_back(z);
	}
	//print();
	for (int k = 0; k < K; k++) {	//k년 후
		for (int season = 0; season < 4; season++) {

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (season == 0) { //봄
						//먹을 수 있는 가장 작은 나무 탐색
						int namoo_i = 0;
						int die_namoo = 0;
						//queue<int> namoo_q;
						//오름차순이냐? 나무정렬
						sort(graph[i][j].namoo_info.begin(), graph[i][j].namoo_info.end());

						int k = 0;
						while (k < graph[i][j].namoo_info.size()) {
							if (graph[i][j].namoo_info[k] > graph[i][j].yangboon) {

								//죽은나무양분
								die_namoo += graph[i][j].namoo_info[k] / 2;
								//나무죽음, 벡터에서 삭제
								graph[i][j].namoo_info.erase(graph[i][j].namoo_info.begin() + k);

							}
							else {
								//양분먹음
								graph[i][j].yangboon -= graph[i][j].namoo_info[k];
								//나무나이증가
								graph[i][j].namoo_info[k]++;
								//다음나무
								k++;
							}
						}

						//죽은나무 양분으로 추가
						graph[i][j].yangboon += die_namoo;

					}
					else if (season == 1) { //여름
						//봄에 죽은나무가 양분으로 추가

					}

					else if (season == 2) { //가을
						for (int k = 0; k < graph[i][j].namoo_info.size(); k++) {
							if (graph[i][j].namoo_info[k] % 5 == 0) {
								//5n 이면 인접나무 번식
								for (int d = 0; d < 8; d++) {
									//벗어나는경우
									if (i + dy[d] < 0 || i + dy[d] >= N || j + dx[d] < 0 || j + dx[d] >= N)continue;
									//번식
									graph[i + dy[d]][j + dx[d]].namoo_info.push_back(1);
								}
							}
						}
					}
					else if (season == 3) { //겨울
						//양분 뿌림
						graph[i][j].yangboon += A[i][j];
					}
				}
			}
		}
	}

	//print();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += graph[i][j].namoo_info.size();
		}
	}
	cout << answer << endl;
	return 0;
}

void print() {
	cout << endl << "양분";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j].yangboon << " ";
		}
		cout << endl;
	}
	cout << "나무"<<endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j].namoo_info.empty())
				cout << 'x' << " ";
			else
				cout << graph[i][j].namoo_info[0] << " ";
		}
		cout << endl;
	}
}