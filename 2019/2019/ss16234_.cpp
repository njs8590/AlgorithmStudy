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

int N; //�迭 NxN
int L, R; //�α����� L�̻� R ����

graph A[50][50];

//4����
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
		//����Ž���ϸ鼭 nation �з�
		//bfs �������
		int cur_nation_num = 0;

		sum_count sumcnt[2501];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (is_visited[i][j] == true) { continue; }

				queue<pos> q;
				q.push({ i,j });
				A[i][j].nation = ++cur_nation_num;
				is_visited[i][j] = true;	//node�� �� ���� ����.
				
				//print();
				while (!q.empty()) {
					pos cur = q.front();
					q.pop();
					//�α������� + ����open �� ����
					A[cur.y][cur.x].nation = cur_nation_num;
					sumcnt[cur_nation_num].sum += A[cur.y][cur.x].value;
					//cout << cur.y << " " << cur.x << endl;
					sumcnt[cur_nation_num].count++;

					//node �������� 4���� Ž��
					for (int d = 0; d < 4; d++) {
						pos next;
						next.y = cur.y + dy[d];
						next.x = cur.x + dx[d];

						if (next.y < 0 || next.y >= N || next.x < 0 || next.x>= N) { continue; }//�������
						if (is_visited[next.y][next.x] == true) { continue; }//�湮������ ����
						//���� �����Ѵٸ� push
						//���� 1 : ���̰� L�̻� R����
						int diff;
						diff = abs(A[cur.y][cur.x].value - A[next.y][next.x].value);
						if (L <= diff && diff <= R) {
							q.push(next);
							is_visited[next.y][next.x] = true;
							//new ���� �߻�
							is_update = true;
						}
					}
				}

			}
		}

		//�α� �̵�
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[i][j].value = sumcnt[A[i][j].nation].sum / sumcnt[A[i][j].nation].count;
				//A�ʱ�ȭ
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