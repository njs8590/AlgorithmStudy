/*
* problem: https://www.acmicpc.net/problem/10825
* algorithm:

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// typedef
typedef struct st
{
	string name;
	int lang;
	int eng;
	int math;
}st;
// function pre-defined
bool comp(const st& a, const st& b);

// global var
int n;

int main(void)
{
	cin >> n;
	//이름, 국어, 영어, 수학
	vector<st> list;

	for (int i = 0; i < n; i++) {
		st temp;
		cin >> temp.name >> temp.lang >> temp.eng >> temp.math;
		list.push_back(temp);
	}

	sort(list.begin(), list.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << list[i].name << "\n";
	}

	return 0;
}

bool comp(const st& a, const st& b)
{
	/*
	1. 국어 점수가 감소하는 순서로
	2. 국어 점수가 같으면 영어 점수가 증가하는 순서로
	3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
	4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로(단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
	*/

	if (a.lang != b.lang)
		return a.lang > b.lang;
	else if (a.eng != b.eng)
		return a.eng < b.eng;
	else if (a.math != b.math)
		return a.math > b.math;
	else
		return a.name < b.name;
}