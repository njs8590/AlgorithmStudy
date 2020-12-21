/*
* ����: https://www.acmicpc.net/problem/1715
*       ī�� �����ϱ�
* ����: Priority Queue
* ����: Priority Queue����: https://travelbeeee.tistory.com/126
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

// global var
// priority_queue<�ڷ���, Container, ���Լ�>
priority_queue<int, vector<int>, greater<int>> pq;
int N;
ll answer;

int main(void)
{
	answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int cardset;
		cin >> cardset;
		pq.push(cardset);
	}

	while (!pq.empty())
	{
		
		int first = pq.top();
		pq.pop();
		if (pq.empty()) break;
		int second = pq.top();
		pq.pop();
		answer += first + second;
		pq.push(answer);
	}
	cout << answer << endl;

	return 0;
}