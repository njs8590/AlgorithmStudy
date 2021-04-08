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
	//�̸�, ����, ����, ����
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
	1. ���� ������ �����ϴ� ������
	2. ���� ������ ������ ���� ������ �����ϴ� ������
	3. ���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
	4. ��� ������ ������ �̸��� ���� ������ �����ϴ� ������(��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)
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