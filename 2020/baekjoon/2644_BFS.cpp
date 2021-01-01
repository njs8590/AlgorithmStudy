/*
* Problem:   https://www.acmicpc.net/problem/2644
*            촌수계산
* Algorithm: BFS
*  
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

#define NODEMAX 101

using namespace std;

// typedef
typedef struct st {
	int node;
	int depth;
}st;

// function pre-defined

// global var
int N; // 전체사람 수 
int p1, target; // 구해야 하는 두사람의 번호
int M; // 관계 input 수
queue<st> q;
vector<vector<int>> childList, parentList;
int answer;
int start;

int main(void)
{
	// input
	cin >> N >> p1 >> target >> M;

	// assign
	childList.assign(N+1, vector<int>());
	parentList.assign(N+1, vector<int>());

	for (int m = 0; m < M; m++) {
		int parent, child;
		cin >> parent >> child;

		parentList[child].push_back(parent);
		childList[parent].push_back(child);

		if (parent == p1) q.push({ child,1 });
		if (child == p1) q.push({ parent,1 });
	}

	bool isVisited[NODEMAX];
	for (int i = 0; i <= M; i++) isVisited[i] = false;

	answer = -1;

	while (!q.empty()) {
		int curnode = q.front().node;
		int curdepth = q.front().depth;
		q.pop();
		
		if (isVisited[curnode]) continue;
		// find answer
		if (curnode == target){
			answer = curdepth;
		}

		isVisited[curnode] = true;

		// 다음경로
		for (int i = 0; i < parentList[curnode].size(); i++) {
			int temp = parentList[curnode][i];
			if (isVisited[temp]) continue;
			q.push({ temp, curdepth + 1 });
		}
		for (int i = 0; i < childList[curnode].size(); i++) {
			int temp = childList[curnode][i];
			if (isVisited[temp]) continue;
			q.push({ temp, curdepth + 1 });
		}
	}

	cout << answer << endl;

	return 0;
}
