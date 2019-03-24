#include<vector>
#include<iostream>
#include<stack>

using namespace std;

typedef struct pos {
	int x, y;
}pos;

void check_graph(pos start, pos end);
pos op(pos start, int op);

int N;	//�巡�� Ŀ���� ����
int x, y, d, g;
//(������), ����, ����
int graph[101][101][101][101] = { 0, };

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;

		//���⼭ ¥���.

		stack<int> originstack;
		originstack.push(d);

		pos end_pos = { x,y };
		pos start_pos;

		for (int j = 0; j <= g; j++) {	//���븸ŭ �巡��Ŀ�� �����

			stack<int> tempstack;
			tempstack = originstack;

			for (int k = 0; k < tempstack.size(); k++) {	//1, 2, 4, 8 ,,,

				start_pos = end_pos;	//start=end �� �ΰ�, end = op(start)

				int newop = tempstack.top();
				tempstack.pop();
				newop = (newop + 1) % 4;	//90�� ȸ���� op
				originstack.push(newop);	//op����

				end_pos = op(start_pos, newop);	//start_pos���� ��� ���� ���� end_pos
				//start, end ���
				check_graph(start_pos, end_pos);
			}
		}
	}//graph�� ��ϿϷ�.

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cout << graph[i][j][i][j] << " ";
		}cout << endl;
	}


}

void check_graph(pos start,pos end) {
	graph[start.x][start.y][end.x][end.y] = 1;
	graph[end.x][end.y][start.x][start.y] = 1;
}

pos op(pos start, int op) {
	if (op == 0) {
		start.x++;
	}
	else if (op == 1) {
		start.y--;
	}
	else if (op == 2) {
		start.x--;
	}
	else if (op == 3) {
		start.y++;
	}
	return start;
}