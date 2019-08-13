/********************
�౸�� �ϱ� ���� ���λ�� N�� - ¦��
��ŸƮ �� N/2, ��ũ �� N/2
��ȣ 1~N
S[i][j] = i �� j�� �Բ� ���� �� �������� �ɷ�ġ
S[j][i]�� �ٸ� ���� ����.
�� ���� �ɷ�ġ�� ���̸� �ּ�ȭ
N * N �׷��� S[][]

*******************/


#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//struct

//func
void dfs(vector<int> start, int cur_person);
int cal(vector<int> vec);

//global var
int N;
int S[21][21];
int answer = 40000;
int link_arr[21] = { 0, };	//0�̸� link��

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		vector<int> start;

		start.push_back(i);
		link_arr[i] = 1;
		dfs(start, i);
		start.pop_back();
		link_arr[i] = 0;
	}

	printf("%d\n", answer);
}

void dfs(vector<int> start, int cur_person)
{
	
	//start ���� N/2 �� �Ǹ� ���
	if (start.size() == N / 2) {
		vector<int> link;

		for (int i = 0; i < N; i++) {
			if (link_arr[i] == 0) {
				link.push_back(i);
			}
		}

		int start_score, link_score;

		start_score = cal(start);
		link_score = cal(link);

		int candi;
		candi = abs(start_score - link_score);
		if (answer > candi) {
			answer = candi;
		}

	}
	else
	{
		for (int i = cur_person+1; i < N; i++) {
			start.push_back(i);
			link_arr[i] = 1;
			dfs(start, i);
			start.pop_back();
			link_arr[i] = 0;
		}
	}
}

int cal(vector<int> vec)
{
	int res = 0;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (i == j)continue;
			int first, second;
			first = vec[i];
			second = vec[j];
			res += S[first][second];
		}
	}

	return res;
}