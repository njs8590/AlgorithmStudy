/******************
https://www.acmicpc.net/problem/14890
����
N * N �׷���
�׷��� ���� = �� ���� ����
������ ���� L : L��ŭ �׷����� ������
���δ� ���� ĭ�� ����
������ ���̰� 1�� �ƴϸ� ���� x
���������� ���ӵǾ����
1. �����ϴٰ� �����̰� �ٸ���� �߻�
2. ���θ� ���� �� �ִ���?
3. �� ���� ���ٸ� ���� �濡 ���� ��ġ,
4. �� ���� ���ٸ� ���� �濡 ���� ��ġ
5. ������ �����ϸ� �� �� �ִ� ���.
�׷����� ��, �� ���� �� ���� -> ���డ������?

******************/

#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//func
bool move();

//global var
int N; //�׷��� ũ��
int L; //���� ����
int graph[101][101];
int line[101];
int answer = 0;


int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	//���� ���� - ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			line[j] = graph[i][j];
		}
		if (move() == true) {
				answer++;
		}
	}
	//���� ���� - ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			line[j] = graph[j][i];
		}
		if (move() == true) {
			answer++;
		}
	}
	printf("%d\n", answer);
}

bool move() {

	int cur = 0;
	int count_L = 1;
	int visited[101] = { 0, };
	visited[0] = 1;

	bool is_updated = true;
	while (is_updated==true) {
		is_updated = false;
		int next = cur + 1;

		//�����̰� �������
		if (line[next] == line[cur]) {
			//����
			cur = next;
			is_updated = true;
			if (visited[cur] == 0) {
				count_L++;
				visited[cur] = 1;
			}
		}

		//�������� 2�̻��� ���
		else if (abs(line[next] - line[cur]) >= 2) {
			//����
		}

		//������ ���� �� �������
		else if (line[next] > line[cur]) {
			if (count_L >= L) {
				cur = next;
				is_updated = true;
				count_L = 1;
			}
		}

		//������ ���� �� ���� ���
		else if (line[next] < line[cur]) {
			//������ �濡 ���θ� ���� �� �ִ���
			count_L = 0;
			for (int i = 0; i < L; i++) {
				if (line[next] == line[next+i]) {
					visited[next+i] = 1;
					count_L++;
				}
			}
			if (count_L >= L) {
				
				is_updated = true;
				cur = next;
				count_L = 0;
			}
		}
		//������ ĭ�� �����Ѱ��
		if (cur == N - 1) {
			return true;
		}
	}

	return false;
}