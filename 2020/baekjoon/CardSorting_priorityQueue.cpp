/*
* 문제: https://www.acmicpc.net/problem/1715
*       카드 정렬하기
* 종류: Priority Queue
* 참고: Priority Queue사용법: https://travelbeeee.tistory.com/126
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
// priority_queue<자료형, Container, 비교함수>
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