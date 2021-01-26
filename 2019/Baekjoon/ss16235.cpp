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

//8����
int dy[] = { -1,-1,-1,0,0,+1,+1,+1};
int dx[] = { -1,0,+1,-1,+1,-1,0,+1};

int main()
{
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];	//��� �Է�
			graph[i][j].yangboon = 5;
		}
	}
	//�ʱ⳪����ġ �Է�
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int r, c;
		r = x - 1; c = y - 1;
		graph[r][c].namoo_info.push_back(z);
	}
	//print();
	for (int k = 0; k < K; k++) {	//k�� ��
		for (int season = 0; season < 4; season++) {

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (season == 0) { //��
						//���� �� �ִ� ���� ���� ���� Ž��
						int namoo_i = 0;
						int die_namoo = 0;
						//queue<int> namoo_q;
						//���������̳�? ��������
						sort(graph[i][j].namoo_info.begin(), graph[i][j].namoo_info.end());

						int k = 0;
						while (k < graph[i][j].namoo_info.size()) {
							if (graph[i][j].namoo_info[k] > graph[i][j].yangboon) {

								//�����������
								die_namoo += graph[i][j].namoo_info[k] / 2;
								//��������, ���Ϳ��� ����
								graph[i][j].namoo_info.erase(graph[i][j].namoo_info.begin() + k);

							}
							else {
								//��и���
								graph[i][j].yangboon -= graph[i][j].namoo_info[k];
								//������������
								graph[i][j].namoo_info[k]++;
								//��������
								k++;
							}
						}

						//�������� ������� �߰�
						graph[i][j].yangboon += die_namoo;

					}
					else if (season == 1) { //����
						//���� ���������� ������� �߰�

					}

					else if (season == 2) { //����
						for (int k = 0; k < graph[i][j].namoo_info.size(); k++) {
							if (graph[i][j].namoo_info[k] % 5 == 0) {
								//5n �̸� �������� ����
								for (int d = 0; d < 8; d++) {
									//����°��
									if (i + dy[d] < 0 || i + dy[d] >= N || j + dx[d] < 0 || j + dx[d] >= N)continue;
									//����
									graph[i + dy[d]][j + dx[d]].namoo_info.push_back(1);
								}
							}
						}
					}
					else if (season == 3) { //�ܿ�
						//��� �Ѹ�
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
	cout << endl << "���";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j].yangboon << " ";
		}
		cout << endl;
	}
	cout << "����"<<endl;
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