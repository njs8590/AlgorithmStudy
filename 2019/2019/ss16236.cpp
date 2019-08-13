/*****
graph size = N * N
����� M����
�Ʊ��� 1���� - ó�� ũ�� 2
��ĭ�� ����� �ִ� 1����
����1) �ڱ⺸�� ū ������ ������ �� ����.
����2) �ڱ⺸�� ���� ����⸸ ���� �� ����.
		= ũ�Ⱑ ���� ������ ���� �� ������ ������ �� ����.
����3) ���尡��� ����⸦ �Դ´�
����4) �Ÿ��� ���� ����Ⱑ ���ٸ� -> ������� ���� ����⸦ �Դ´�.
����5) �ڱ� ũ�⸸ŭ ����⸦ ������ ������
����) ���̻� ���� ����Ⱑ ������ ����!

input)
N �׷��� ũ��
���� ����. 0= ��ĭ, 1~6 = ����� ũ��, 9 = �Ʊ���

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
int dy[] = { -1,0,0,+1 };	//���޿���

int main()
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 9) {
				shark_pos = { i,j,0 };	//����� ��ġ
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
		//is_visited[shark_pos.y][shark_pos.x] = true;	//���� �����ġ
		
		pos candi_pos;	//��Ƹ��� �����

		while (!q.empty()) {
			pos cur_pos = q.front();
			q.pop();

			//ó�� ���� ����⸦ �߰��� ����
			//�ð��������� �����ð��̸� ť�� �� �ְ�, ���ؼ� candi�� ����.
			if (find_eating == true&&graph[cur_pos.y][cur_pos.x]!=0&&graph[cur_pos.y][cur_pos.x]<shark_size) {
				if (cur_pos.time > candi_pos.time)continue;	//����⸦ �߰��ߴµ�, ���� �ð��� ��� Ž���Ϸ� �ϸ� continue
				
				if (cur_pos.y < candi_pos.y) {	//�� ����������
					candi_pos = cur_pos;
				}
				else if (cur_pos.y == candi_pos.y && cur_pos.x < candi_pos.x) {	//���� �����ε�, �� ���ʿ�������
					candi_pos = cur_pos;
				}
			}

			if (graph[cur_pos.y][cur_pos.x]!=0 && graph[cur_pos.y][cur_pos.x] < shark_size && find_eating==false) {
				//������ && �������ֵ� && ó�� ã�����̴�.
				find_eating = true;
				candi_pos = cur_pos;
				is_update = true;	//����⸦ ��Ƹ��� �� �ִ�.
				continue;
			}

			//�̵��� ������ �ð����
			//4���� Ž���ϰ� ť������
			//�ϴ� �� Ž���ϰ� ���� �� �ִ¾� �� ����4�� �����ϴ� �ָ� ����.
			//�ٽ� ť ����
			
			for (int d = 0; d < 4; d++) {
				pos next;
				next.x = cur_pos.x + dx[d];
				next.y = cur_pos.y + dy[d];
				next.time = cur_pos.time + 1;	//����ĭ�� ����ĭ���� �ϳ� ������ �ð�
				
				if (next.x >= N || next.x < 0 || next.y >= N || next.y < 0)continue;//�� ���� �� �� ����
				if (graph[next.y][next.x] > shark_size) continue; //����Ⱑ ���� ũ�� �� �� ����
				if (is_visited[next.y][next.x] == true) continue;

				//system("pause");

				is_visited[next.y][next.x] = true;
				q.push(next);
			}
			
		}

		//candi_pos �� ��Ƹ����� ��.
		if (is_update) {
			//cout << "ũ��" << endl;
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