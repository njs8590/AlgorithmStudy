#include<iostream>
#include<vector>

using namespace std;

int N;
int graph[101][101] = { 0, };

//0:x+1, 1:y-1, 2:x-1, 3:y+1
int dx[] = { +1,0,-1,0 };
int dy[] = { 0,-1,0,+1 };

int answer = 0;

int main()
{
	cin >> N;

	for (int n = 0; n < N; n++) {
		
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		//현재좌표 기록
		graph[y][x] = 1;
		//op를 먼저 기록
		vector<int> op;
		//g==0인경우
		op.push_back(d);

		//g>=1부터
		if (g >= 1) {
			for (int i = 0; i < g; i++) {
				int op_size = op.size();
				//추가되는 op는 LIFO 방식
				for (int j = op_size - 1; j >= 0;j--) {
					int newop = (op[j] + 1) % 4;
					op.push_back(newop);
				}
			}
		}
		
		//op하나씩 읽으면서 graph에 기록
		for (int i = 0; i < op.size(); i++) {
			x = x + dx[op[i]];
			y = y + dy[op[i]];
			graph[y][x] = 1;
		}
		//cout << "끝?" << endl;
		/*
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}//graph 기록 끝

	//사각형 찾기
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (graph[i][j] == 1) {
				if (graph[i + 1][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j + 1] == 1) {
					//cout << "??";
					answer++;
				}
			}
		}
	}

	cout << answer << endl;
}