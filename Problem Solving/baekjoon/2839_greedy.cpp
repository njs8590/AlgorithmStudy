/*
* problem: https://www.acmicpc.net/problem/2839
* algorithm:

*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef

// function pre-defined

// global var


int main(void)
{
	int N; // 배달해야하는 무게 (5kg, 3kg)
	cin >> N;

	int answer = 0;
	int five_cnt = 0;
	int three_cnt = 0;

	five_cnt = N / 5;
	N = N % 5;

	while (true) {
		// 남은 무게를 3으로 들수있는가
		if (N % 3 == 0) {
			three_cnt = N / 3;
			answer = five_cnt + three_cnt;
			break;
		}
		else if(five_cnt>0){
			// 5를 하나 줄인다
			five_cnt--;
			N += 5;
		}
		// 3으로만 들수있는가
		if (five_cnt == 0 && N % 3 > 0) {
			answer = -1;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}