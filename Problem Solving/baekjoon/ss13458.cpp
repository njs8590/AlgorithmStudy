/**************
시험 감독

N 시험장 수
i번 시험장 응시자수 A[i]
감독관 = 총감독관, 부감독관
총감독관 = B명 감시
부감독관 = C명 감시
총감독관 1명, 부감독관 여러명
필요한 감독관의 최소???



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