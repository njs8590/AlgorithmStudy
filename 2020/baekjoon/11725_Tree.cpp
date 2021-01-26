/*
* problem: https://www.acmicpc.net/problem/11725
* algorithm:

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined
void bfs();

// global var
vector<vector<int>> list;
bool isVisited[100001];
int n;
vector<int> parentList;

int main(void)
{

	cin >> n;
	list.assign(n+1, vector<int>());
	parentList.assign(n + 1, int());

	int node1, node2;

	for (int i = 0; i < n-1; i++){
		cin >> node1 >> node2;
		list[node1].push_back(node2);
		list[node2].push_back(node1);
	}
	
	bfs();

	for (int i = 2; i < parentList.size(); i++) {
		cout << parentList[i] << "\n";
	}

	return 0;
}

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)isVisited[i] = false;

	q.push(1);
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		isVisited[parent] = true;

		for (int i = 0; i < list[parent].size(); i++) {
			int child = list[parent][i];

			if (isVisited[child])continue;
			q.push(child);
			parentList[child] = parent;
		}
	}

}