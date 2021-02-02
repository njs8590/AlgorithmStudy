/*
* problem: https://programmers.co.kr/learn/courses/30/lessons/43165
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct st
{
	int num;
	int sum;
}st;

int solution(vector<int> numbers, int target);

int main(void)
{
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);

	cout << solution(temp, 3) << endl;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	
	return answer;
}