/*
* problem: https://programmers.co.kr/learn/courses/30/lessons/43165
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int solution(vector<int> numbers, int target);
void dfs(vector<int> numbers, int target, int sum);

int candi;

int main(void)
{
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);

	candi = 0;

	cout << solution(temp, 3) << endl;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	dfs(numbers, target, 0);
	answer = candi;
	return answer;
}

void dfs(vector<int> numbers, int target, int sum)
{
	if (numbers.empty()) {
		if (sum == target)candi++;
		return;
	}
	int cur = numbers.back();
	numbers.pop_back();
	dfs(numbers, target, sum + cur);
	dfs(numbers, target, sum - cur);
	numbers.push_back(cur);
}