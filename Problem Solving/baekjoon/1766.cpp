//https://www.acmicpc.net/problem/1766
//��������, ��
//
//N���� ������ ��� Ǯ��� �Ѵ�.
//�켱���� ���� ����, �����ϸ� �����

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
		leftConditon[i] = 0;	//���� ���� ������ �� �ִ� ����
	}

	for (int i = 0; i < M; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		leftConditon[second]++;	//second�� ����Ƿ��� ����Ǿ�� �� ���� ��
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