/*
* Problem: https://www.acmicpc.net/problem/14501
* Algorithm: DP
* N+1 �� ���, N�ϱ��� �ִ��� ���� ���� ó��
* �Ϸ��ϳ��� ���δٸ������ ���.
* Ti: ���Ϸ�ð� (��)
* Pi: ����
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined
void dfs(int temp_T[], int candi, int pos);

// global var
int N; // 1<= N <= 15
int T[16]; // 1<= Ti <= 5
int P[16]; // 1<= Pi <= 1,000
long long answer; 

int main(void)
{
	// init
	answer = 0;

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(T, 0, 0);

	cout << answer << endl;

	return 0;
}

void dfs(int temp_T[], int candi, int pos)
{
	//for (int i = 0; i < N; i++) {
	//	cout << temp_T[i] << " ";
	//}
	//cout << ":" << candi;
	//cout << endl;

	for (int i = pos; i < N; i++) {
		if (temp_T[i] == -1)continue;
		
		int spend_time = temp_T[i]; // i��° ����� �Ұ��
		if (i + spend_time > N)continue; // ������� �Ѿ�� ���� ó���Ҽ�����.
		candi += P[i];
		// backup
		int backup_T[16];
		for (int i = 0; i < N; i++) {
			backup_T[i] = temp_T[i];
		}

		// spend_time ���ȿ��� ���� ó���Ҽ�����. -1 �� ǥ��
		for (int j = i; j < i + spend_time; j++) {
			if (j >= N)continue;
			temp_T[j] = -1;
		}
		
		// recurr
		dfs(temp_T, candi, i+spend_time);
		
		// rollback
		for (int i = 0; i < N; i++) {
			temp_T[i] = backup_T[i];
		}
		candi -= P[i];
	}
	
	if (candi > answer) answer = candi;
}