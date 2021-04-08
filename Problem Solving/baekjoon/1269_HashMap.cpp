/*
* problem: https://www.acmicpc.net/problem/1269
* algorithm: ...

*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

// typedef
typedef long long ll;

// function pre-defined

// global var


int main(void)
{
	ll cnt_A, cnt_B;
	map<ll, ll> A, B;

	cin >> cnt_A >> cnt_B;
	ll res = cnt_A + cnt_B;
	
	for (ll i = 0; i < cnt_A; i++) {
		ll temp;
		cin >> temp;
		A[temp]++;
	}

	for (ll i = 0; i < cnt_B; i++) {
		ll temp;
		cin >> temp;
		if (A[temp] > 0) {
			A[temp]--;
			res-=2;
		}
	}

	cout << res << endl;
	return 0;
}