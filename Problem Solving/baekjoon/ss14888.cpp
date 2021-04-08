/***************
https://www.acmicpc.net/problem/14888
연산자 끼워넣기

N개의 수로 이루어진 수열 A[]
N-1개의 연산자
수의 순서를 바꾸면 안된다
수 사이에 연산자를 끼워넣는다.
연산자 우선순위를 무시하고 앞에서부터 계산.
나눗셈은 정수 몫만
결과의 최대 최소를 출력

***************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;	//수의 개수
int A[12]; //수열
int op[4]; //연산자 +-*/

long long answer_max, answer_min;

void dfs(long long res, int next_index);

int main()
{
	answer_max = -1000000001;
	answer_min = +1000000001;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	dfs(A[0], 1);

	cout << answer_max << endl << answer_min << endl;

	return 0;
}

void dfs(long long res, int next_index)
{
	
	if (next_index == N) {
		//printf("%d ", res);
		//system("pause");
		//계산이 완료된 경우
		if (res > answer_max) {
			answer_max = res;
		}
		if (res < answer_min) {
			answer_min = res;
		}
	}

	else if (next_index < N) {
		for (int i = 0; i < 4; i++) {

			long long backup;
			backup = res;

			if (op[i] == 0)continue;//해당 op가 없는 경우

			if (i == 0) {
				res = res + A[next_index];
			}
			else if (i == 1) {
				res = res - A[next_index];
			}
			else if (i == 2) {
				res = res * A[next_index];
			}
			else if (i == 3) {
				res = res / A[next_index];
			}

			op[i]--;
			dfs(res, next_index + 1);
			op[i]++;
			res = backup;

		}
	}
	
}