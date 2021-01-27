/*
* problem: https://www.acmicpc.net/problem/1068
* algorithm: Tree

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined
void dfs(int curnode);

// global var
vector<vector<int>> child;
int erasenode;
int answer;

int main(void)
{
	int n;
	cin >> n;

	int root = 0;

	//init
	child.assign(n, vector<int>());
	answer = 0;

	for (int curnode = 0; curnode < n; curnode++) {
		int parent;
		cin >> parent;

		if (parent == -1) { //root
			root = curnode;
			continue;
		}
		child[parent].push_back(curnode);
	}

	cin >> erasenode;

	if (erasenode != root) dfs(root);

	cout << answer;

	return 0;
}

void dfs(int curnode)
{
	bool leaf = true;
	for (int i = 0; i < child[curnode].size(); i++) {
		int next = child[curnode][i];

		if (next == erasenode)continue;
		dfs(next);
		leaf = false;
	}
	if (leaf)answer++;
}