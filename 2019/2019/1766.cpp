//https://www.acmicpc.net/problem/1766
//위상정렬, 힙
//
//N개의 문제는 모두 풀어야 한다.
//우선순위 높은 문제, 가능하면 쉬운문제

#define MAXN 32005
#define MAXM 100005

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	int leftConditon[MAXN];
	vector<int> prioThan[MAXN];

	for (int i = 0; i <= N; i++) {
		leftConditon[i] = 0;	//지금 당장 실행할 수 있는 상태
	}

	for (int i = 0; i < M; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		leftConditon[second]++;	//second가 실행되려면 선행되어야 할 조건 수
		prioThan[first].push_back(second);
	}

	queue<int> q;
	int i = 1;
	while (leftConditon[i]) {
		i++;
	}
	leftConditon[i]--;
	q.push(i);
	for (int j = 0; j < prioThan[i].size(); j++) {
		leftConditon[prioThan[i][j]]--;
		//printf("prio:%d\n", prioThan[i][j]);
	}

	while(!q.empty() && i<=N){
		int cur;
		cur = q.front();
		q.pop();
		printf("%d ", cur);
		i = 1;
		while (leftConditon[i] && i<=N) {
			i++;
		}
		if (leftConditon[i] == 0) {
			leftConditon[i]--;
			q.push(i);
			for (int j = 0; j < prioThan[i].size(); j++) {
				//printf("prio:%d\n", prioThan[i][j]);
				leftConditon[prioThan[i][j]]--;
			}
		}
	}
	cout << endl;
	
	return 0;
}