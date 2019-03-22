#include <stdio.h>
#include <queue>

using namespace std;

struct SHARK {
	int y, x, time;
};

int n;	//N x N ũ�� �迭
int map[20][20];	//�迭 �ִ�ũ��

int shark_size, shark_eat;
SHARK shark;

const int dy[] = { 0, 0, -1, +1 };
const int dx[] = { -1, +1, 0, 0 };

int main()
{
	scanf("%d", &n);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;	//ó�� ��� ��ġ
				shark_size = 2, shark_eat = 0;	//��� �ʱⰪ 2, ��� ������ 0? ����
				map[y][x] = 0;	//���� ��� �ڸ��� 0���� ����
			}
		}
	}

	bool is_update = true;
	while (is_update) {	//update �� �߻��ϸ� ���
		is_update = false;

		bool visited[20][20] = { false, };
		queue<SHARK> q;
		visited[shark.y][shark.x] = true;	//���� ��� ��ġ �湮����.
		q.push(shark);	//�ʱ� ��ġ�� q�� ����.

		SHARK candi;	//���� �����
		candi.y = 20, candi.time = -1;	//�ʿ��� ����� �ʴ� candi�� ��������

		while (!q.empty()) {	//q�� �̿��� ��ȸ ����
			SHARK cur = q.front();  q.pop();

			if (candi.time != -1 && candi.time < cur.time) {
				break;
			}

			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
			// ������ġ ����� ũ�� < ��� ũ�� && ������ġ�� ������� (!=0)	
				is_update = true;
				//��Ƹ����� update �Ǿ���.
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}

			//4���� Ž��
			for (int dir = 0; dir < 4; ++dir) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
					continue;
				}

				if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]) {
					//�湮�� ���� ����(false) ��� && ���ũ�� >= ���ߵǴ� ��ġ
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (is_update) {
			shark = candi;
			++shark_eat;
			if (shark_eat == shark_size) {	//��� ������ ũ�⸸ŭ�Ǹ�
				++shark_size;	//���ũ������
				shark_eat = 0;	//�����Ŵ� 0����
			}
			map[shark.y][shark.x] = 0;	//�����ġ �ٽ� 0���� �ؼ� ����
		}
	}

	printf("%d\n", shark.time);

	return 0;
}