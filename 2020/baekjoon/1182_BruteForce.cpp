/*
* problem: https://www.acmicpc.net/problem/1182
* algorithm:brute-force

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef
typedef long long ll;

// function pre-defined
void dfs(vector<ll> list, ll sum, int pos);

// global var
int S; // 합
int answer;

int cnt = 0;

int main(void)
{
	int N; // 정수 개수
	
	vector<ll> list;
	ll temp;

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		cin >> temp; 
		list.push_back(temp);
	}

	answer = 0;

	dfs(list, 0, 0);

	cout << answer << endl;

	return 0;
}


void dfs(vector<ll> list, ll sum, int pos)
{
	if (list.empty()) return;
	
	for (int i = pos; i < list.size(); i++) {
		
		ll cur = list[i];

		if (sum+cur == S) answer++;
		
		list[i] = 0;
		if(i<list.size()) dfs(list, sum + cur, i + 1);
		list[i] = cur;

	}
}
