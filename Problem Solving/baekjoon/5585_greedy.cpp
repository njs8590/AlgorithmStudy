/*
* problem:https://www.acmicpc.net/problem/5585
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
	int amt; // 내야할 금액
	
	cin >> amt;
	
	amt = 1000 - amt;
	int answer = 0;

	answer += amt / 500;
	amt = amt % 500;

	answer += amt / 100;
	amt = amt % 100;

	answer += amt / 50;
	amt = amt % 50;

	answer += amt / 10;
	amt = amt % 10;

	answer += amt / 5;
	amt = amt % 5;

	answer += amt;

	cout << answer << endl;

	return 0;
}