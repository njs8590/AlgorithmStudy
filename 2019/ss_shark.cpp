#include <stdio.h>
#include <queue>

using namespace std;

struct SHARK {
	int y, x, time;
};

int n;	//N x N 크기 배열
int map[20][20];	//배열 최대크기

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
				shark.y = y, shark.x = x, shark.time = 0;	//처음 상어 위치
				shark_size = 2, shark_eat = 0;	//상어 초기값 2, 상어 먹은거 0? 설정
				map[y][x] = 0;	//이후 상어 자리를 0으로 만듦
			}
		}
	}

	bool is_update = true;
	while (is_update) {	//update 가 발생하면 계속
		is_update = false;

		bool visited[20][20] = { false, };
		queue<SHARK> q;
		visited[shark.y][shark.x] = true;	//현재 상어 위치 방문했음.
		q.push(shark);	//초기 위치를 q에 넣음.

		SHARK candi;	//먹은 물고기
		candi.y = 20, candi.time = -1;	//맵에서 벗어나지 않는 candi를 먹을려고

		while (!q.empty()) {	//q를 이용한 순회 구현
			SHARK cur = q.front();  q.pop();

			if (candi.time != -1 && candi.time < cur.time) {
				break;
			}

			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
			// 현재위치 물고기 크기 < 상어 크기 && 현재위치가 물고기라면 (!=0)	
				is_update = true;
				//잡아먹으면 update 되었다.
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}

			//4방향 탐색
			for (int dir = 0; dir < 4; ++dir) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
					continue;
				}

				if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]) {
					//방문한 적이 없는(false) 경우 && 상어크기 >= 가야되는 위치
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (is_update) {
			shark = candi;
			++shark_eat;
			if (shark_eat == shark_size) {	//상어 먹은게 크기만큼되면
				++shark_size;	//상어크기증가
				shark_eat = 0;	//먹은거는 0으로
			}
			map[shark.y][shark.x] = 0;	//상어위치 다시 0으로 해서 시작
		}
	}

	printf("%d\n", shark.time);

	return 0;
}