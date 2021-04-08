#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int> stndList, vector<int> curList, int idx);
long long sum(vector<int> curList);

int N; // 정수 개수
int S; // 합
int answer;

int main(void)
{	
	vector<int> stndList;
	cin >> N >> S;
	answer = 0;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		stndList.push_back(temp);
	}

	vector<int> curList;
	dfs(stndList, curList, 0);

	cout << answer << endl;

	return 0;
}

void dfs(vector<int> stndList, vector<int> curList, int idx) {

	// condition
	if (!curList.empty() && sum(curList) == S) answer++;
	if (idx == stndList.size()) return;

	// recursive
	for (int i = idx; i < stndList.size(); i++) {
		curList.push_back(stndList[i]);
		dfs(stndList, curList, i+1);
		curList.pop_back();
	}

	return;
}

long long sum(vector<int> curList) {
	long long sum = 0;
	for (int &cur : curList) {
		sum += cur;
	}
	return sum;
}