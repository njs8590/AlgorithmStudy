/**************
���� ����

N ������ ��
i�� ������ �����ڼ� A[i]
������ = �Ѱ�����, �ΰ�����
�Ѱ����� = B�� ����
�ΰ����� = C�� ����
�Ѱ����� 1��, �ΰ����� ������
�ʿ��� �������� �ּ�???



**************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N;
vector<int> A;
int B, C;
long long answer = 0;

int main()
{
	scanf("%d", &N);
	int person;
	for (int i = 0; i < N; i++) {
		scanf("%d", &person);
		A.push_back(person);
	}
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		answer++;
		
		if(A[i]>0){
			answer += A[i] / C;
			if (A[i] % C != 0)
				answer++;
		}
			
	}

	cout << answer << endl;

	return 0;
}