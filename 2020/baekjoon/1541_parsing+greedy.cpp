/*
* problem: https://www.acmicpc.net/problem/1541
* algorithm: parsing + greedy
* input: 55-50+40-30
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<sstream>

using namespace std;

// typedef
typedef long long ll;

// function pre-defined

// global var

int main(void)
{
	string input;
	cin >> input;
	stringstream ss(input);


	ll number;
	bool isMinus = false;

	int sumTemp = 0;

	ll answer = 0;
	while (ss >> number) {
		// 마이너스 처음등장
		if (number < 0 && !isMinus) isMinus = true;
		// 마이너스 두번째 등장
		// => 지금까지 부분합을 answer에서 차감.
		if (number < 0 && isMinus) {
			answer -= sumTemp;
			sumTemp = 0;
		}
		

		// 마이너스가 나오면 다음 마이너스까지 누적
		if (isMinus) {
			if (number < 0)sumTemp -= number;
			else sumTemp += number;
		}
		else {
			answer += number;
		}
	}

	// 루프 종료 후에도 sumTemp 남아있다 = 마이너스 부분합 계산중이었다.
	// => answer에서 차감.
	if (sumTemp > 0)answer -= sumTemp;

	cout << answer << endl;

	return 0;
}