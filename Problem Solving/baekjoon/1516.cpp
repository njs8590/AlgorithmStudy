//게임개발
//https ://www.acmicpc.net/problem/1516
//테크를 타서 각 건물을 짓는 문제인데, 건물이 동시에올라갈 수 있다는 것이 주의할 점이다.
//c의 선행테크가 a,b일때 a와 b가 동시에 지어질 수 있다면, 둘 중에 오래걸리는 시간이 c의 선행시간이 되겠다.


#define MAX 100

#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	vector<int> list[501];
	int prebuildList[501];
	int buildTime[501];
	int answerList[501];
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		prebuildList[i] = 0;
		answerList[i] = 0;
	}

	for (int cur = 1; cur <= N; cur++) {
		scanf("%d", &buildTime[cur]);

		int prebuildCnt = 0;

		while (1) {
			int temp;
			scanf("%d", &temp);
			if (temp == -1)
				break;
			
			list[temp].push_back(cur);
			prebuildCnt++;

		}
		prebuildList[cur] = prebuildCnt;
	}

	/*printf("BuildTime:: ");
	for (int i = 1; i <= N; i++) {
		printf("%d ", buildTime[i]);
	}
	printf("\n");*/

	queue<int> q;

	int minNumber = 0;
	bool check = true;
	while (check) {
		for (int i = 1; i <= N; i++) {
			if (prebuildList[i] == minNumber) {
				q.push(i);
				check = false;
				//printf("qin%d ", i);
			}
		}
		minNumber++;
	}
	//printf("\n");

	
	int answer = 0;
	int addTime[501];
	for (int i = 1; i <= N; i++) {
		addTime[i] = 0;
	}

	while (!q.empty()) {
		int qsize = q.size();
		
		for (int j = 0; j < qsize; j++) {
			int cur = q.front();
			q.pop();
			answerList[cur] = buildTime[cur];

			for (int i = 0; i < list[cur].size(); i++) {

				int nextBuild = list[cur][i];
				prebuildList[nextBuild]--;
				
				if (addTime[nextBuild] < buildTime[cur]) {
					addTime[nextBuild] = buildTime[cur];
				}

				if (prebuildList[nextBuild] == 0) {
					
					buildTime[nextBuild] += addTime[nextBuild];
					q.push(nextBuild);
				}

			}
		}
		
	}
	
	for (int i = 1; i <= N; i++) {
		printf("%d\n", answerList[i]);
	}

	return 0;
}