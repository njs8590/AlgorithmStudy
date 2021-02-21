/*
* problem: https://www.acmicpc.net/problem/2217
* algorithm:
* k개의 로프로 w를 들면 각 로프에 w/k 중량이 작용
* N개의 로프에 대해서 최대중량 input
* 로프들을 사용하여 들 수 있는 최대중량은?
* k( w/k + w/k + ... + w/k) = w
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined
bool cmp(int a, int b);

// global var

int main(void)
{
	int N;
	cin >> N; // N<=100,000

	vector<int> ropes;
	int rope;
	for (int i = 0; i < N; i++) {
		cin >> rope;
		ropes.push_back(rope);
	}

	sort(ropes.begin(), ropes.end(), cmp);

	int candi = 0;
	int k = 1;
	int weightSum = 0;
	int w = 0;

	for (int i = 0; i < ropes.size(); i++) {
		int maxWeight = ropes[i] * k;
		if (candi < maxWeight)candi = maxWeight;
		k++;
	}

	cout << candi << endl;

	return 0;
}

bool cmp(int a, int b) {
	return a > b;
}