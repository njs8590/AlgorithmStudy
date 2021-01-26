/***************
https://www.acmicpc.net/problem/14888
������ �����ֱ�

N���� ���� �̷���� ���� A[]
N-1���� ������
���� ������ �ٲٸ� �ȵȴ�
�� ���̿� �����ڸ� �����ִ´�.
������ �켱������ �����ϰ� �տ������� ���.
�������� ���� ��
����� �ִ� �ּҸ� ���

***************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;	//���� ����
int A[12]; //����
int op[4]; //������ +-*/

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
		//����� �Ϸ�� ���
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

			if (op[i] == 0)continue;//�ش� op�� ���� ���

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