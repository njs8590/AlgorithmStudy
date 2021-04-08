#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int INF = 987654321;

void dfs(int node);

int N; //배열크기
int M; //치킨집 수
int graph[50][50];

typedef struct pos {
	int y;
	int x;
}pos;

vector<pos> chicken_pos;
vector<pos> house;
vector<pos> chicken_pick;

int answer = INF;

void print(vector<pos> x);

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				chicken_pos.push_back({ i,j });	//치킨집 위치기억
			}
			else if (graph[i][j] == 1) {
				house.push_back({ i,j });	//집 위치 기억
			}
		}
	}

	dfs(0);

	cout << answer << endl;

	return 0;
}

void dfs(int node) {
	
	if (chicken_pick.size() == M) {
		//계산
		int sum=0;
		
		for (int i = 0; i < house.size(); i++) {//r1,c1
			int min_dist = INF;

			for (int j = 0; j < chicken_pick.size(); j++) {//r2,c2
				int r1 = house[i].y; int c1 = house[i].x;
				int r2 = chicken_pick[j].y; int c2 = chicken_pick[j].x;
				//min_dist = 집~ 모든 치킨집 거리 중 최소거리
				
				min_dist = min(min_dist, (abs(r1 - r2) + abs(c1 - c2)) );
				//cout <<"min"<< min_dist << endl;
			}

			sum += min_dist;	//각 집의 최소 치킨거리를 모두 누적
			//cout << "sum"<<sum << endl;
		}

		answer = min(sum, answer);
		
		return;
	}
	
	
	for (int i = node; i < chicken_pos.size(); i++) {
		chicken_pick.push_back(chicken_pos[i]);
		dfs(i+1);
		chicken_pick.pop_back();
	}
}

void print(vector<pos> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i].y << " " << x[i].x << endl;
	}
}