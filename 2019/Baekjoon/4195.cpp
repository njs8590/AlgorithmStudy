#define MAX 200010

#include<map>
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio>

using namespace std;

int parent[MAX];
int num[MAX];
char f1[21], f2[21];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

int m_union(int hashnum1, int hashnum2) {
	hashnum1 = find(hashnum1);
	hashnum2 = find(hashnum2);

	if (hashnum1 != hashnum2) {
		parent[hashnum1] = hashnum2;
		num[hashnum2] += num[hashnum1];
		num[hashnum1] = 1;
	}

	return num[hashnum2];
}

int main(void) {
	
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {

		map<string, int> mp;
		int hash_num = 1;

		int friend_count;
		cin >> friend_count;

		for (int i = 1; i <= 2*friend_count; i++) {
			parent[i] = i;
			num[i] = 1;
		}

		for (int f = 0; f < friend_count; f++) {
			
			scanf("%s %s", &f1, &f2);

			if (mp.count(f1) == 0) {
				mp[f1] = hash_num++;
			}
			if (mp.count(f2) == 0) {
				mp[f2] = hash_num++;
			}
			printf("%d\n", m_union(mp[f1], mp[f2]));
		}
	}
	return 0;
}