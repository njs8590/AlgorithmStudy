/**************
����Ż��
Red, Blue �Ѱ��� graph�� �ְ�, Red�� ������ ���� ������ ����
���� N = i;
���� M = j;
���� �ٱ� ��� ���� ��� ����
���忡�� ������ �Ѱ�
Blue�� ���ۿ� ���� �ȵ�.
�����¿�� ����̱⸸ ����.
������ ���� ���ÿ� ������. Blue�� ���� ����.
Red, Blue ���ÿ� ���� ����.
���ÿ� ����ĭ�� ���� �� ����. ���̻� ������ �ȿ����̸� ����.
�ּ� ������� Red�� ���� �� �ִ���?
10�� �Ѿ�� -1 ���
��ĭ ., ��#, ����o, ����R, B

**************/

#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

//type
typedef struct pos {
	int y;
	int x;
}pos;
typedef struct R_B {
	pos R;
	pos B;
	int time;
}R_B;

int dx[] = { 0,0,-1,+1 };
int dy[] = { -1,+1,0,0 };

//variable
int N, M;
char graph[11][11];
pos R, B, O;
int answer = 11;
bool is_updated = false;

//func

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'R') {
				R = { i,j };
			}
			else if (graph[i][j] == 'B') {
				B = { i,j };
			}
			else if (graph[i][j] == 'O') {
				O = { i,j };
			}
		}
	}

	queue<R_B> q;
	q.push({ R, B, 1 });

	while (!q.empty()) {
		pos cur_R, cur_B;
		int time;
		cur_R = q.front().R;
		cur_B = q.front().B;
		time = q.front().time;
		q.pop();
		
		//R�� ������ ã����
		

		for (int d = 0; d < 4; d++) {//4����
			pos next_R, next_B;
			next_R = cur_R;
			next_B = cur_B;


			bool find_answer = false;
			bool find_check = false;

			while (true) {
				next_R.y += dy[d]; next_R.x += dx[d];
				next_B.y += dy[d]; next_B.x += dx[d];

				//�Ѵ� ���� ���� �� ���� ������.
				if (graph[next_R.y][next_R.x] == '#'&&graph[next_B.y][next_B.x] == '#') {
					next_R.y -= dy[d]; next_R.x -= dx[d];
					next_B.y -= dy[d]; next_B.x -= dx[d];
					break;
				}
				//R�� ��
				else if (graph[next_R.y][next_R.x] == '#') {
					//����
					next_R.y -= dy[d]; next_R.x -= dx[d];
					//B�� ��ġ�� �������� B�� ����, break
					if (next_R.y == next_B.y&&next_R.x == next_B.x) {
						next_B.y -= dy[d]; next_B.x -= dx[d];
						break;
					}
				}
				//B�� ��
				else if (graph[next_B.y][next_B.x] == '#') {
					next_B.y -= dy[d]; next_B.x -= dx[d];
					//R�� ����, break;
					if (next_R.y == next_B.y&&next_R.x == next_B.x) {
						next_R.y -= dy[d]; next_R.x -= dx[d];
						break;
					}
				}

				//R�� ��������
				if (next_R.y == O.y && next_R.x == O.x) {
					//cout << "find!!!!!" << endl;
					find_answer = true;
					find_check = true;
				}
				//B�� ��������
				if (next_B.y == O.y && next_B.x == O.x) {
					//cout << "no....." << endl;
					find_answer = false;
					find_check = true;
					break;
				}
			}

			if (find_answer == true) {
				
				if (answer > time) {
					//cout << "update!!!!!!!!!!!!!!" << endl;
					answer = time;
					//cout << answer;
				}
				break;
			}
			
			if(find_check==false){
				if(next_R.y!=cur_R.y|| next_R.x != cur_R.x|| next_B.y != cur_B.y|| next_B.x != cur_B.x)
					q.push({ next_R, next_B, time + 1 });
			}
					
		}//4��������
		
		if (time == 10) {
			break;
		}
	}

	if (answer>10) {
		answer = -1;
	}
	printf("%d\n", answer);
	
}
