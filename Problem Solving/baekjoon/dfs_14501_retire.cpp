/*
* Problem: https://www.acmicpc.net/problem/14501
* Algorithm: DP
* N+1 일 퇴사, N일까지 최대한 많은 일을 처리
* 하루하나씩 서로다른사람의 상담.
* Ti: 상담완료시간 (일)
* Pi: 페이
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
		
		int spend_time = temp_T[i]; // i번째 상담을 할경우
		if (i + spend_time > N)continue; // 퇴사일이 넘어가는 일은 처리할수없다.
		candi += P[i];
		// backup
		int backup_T[16];
		for (int i = 0; i < N; i++) {
			backup_T[i] = temp_T[i];
		}

		// spend_time 동안에는 일을 처리할수없음. -1 로 표기
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