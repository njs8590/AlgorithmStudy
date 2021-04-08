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
		// ���̳ʽ� ó������
		if (number < 0 && !isMinus) isMinus = true;
		// ���̳ʽ� �ι�° ����
		// => ���ݱ��� �κ����� answer���� ����.
		if (number < 0 && isMinus) {
			answer -= sumTemp;
			sumTemp = 0;
		}
		

		// ���̳ʽ��� ������ ���� ���̳ʽ����� ����
		if (isMinus) {
			if (number < 0)sumTemp -= number;
			else sumTemp += number;
		}
		else {
			answer += number;
		}
	}

	// ���� ���� �Ŀ��� sumTemp �����ִ� = ���̳ʽ� �κ��� ������̾���.
	// => answer���� ����.
	if (sumTemp > 0)answer -= sumTemp;

	cout << answer << endl;

	return 0;
}