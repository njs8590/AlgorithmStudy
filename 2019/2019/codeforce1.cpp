/********************
https://codeforces.com/problemset/problem/977/A
Wrong Subtraction
n �� k�� �־�����
k�� loop
n�� ���ڸ��� 0�� �ƴϸ� -1
n�� ���ڸ��� 0�̸� /10

*********************/

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	int k;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int last = n % 10;
		if (last == 0) {
			n /= 10;
		}
		else {
			n -= 1;
		}
	}

	cout << n << endl;
	return 0;
}