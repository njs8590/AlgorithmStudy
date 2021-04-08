/*
* problem:
* algorithm:

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
typedef struct st
{
	int cnt;
	double percent;
	bool candi;
}st;

// function pre-defined
vector<string> mostActive(vector<string> customers);

// global var
int total;

map<string, st> customMap;


int main(void)
{
	vector<string> list;

	vector<string> temp = mostActive(list);
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << endl;

	return 0;
}

vector<string> mostActive(vector<string> customers) {
	for (int i = 0; i < customers.size(); i++) {
		st temp;
		temp = customMap[customers[i]];
		temp.cnt++;
		total++;
		temp.candi = false;

		customMap[customers[i]] = temp;		
	}

	for (const auto& item : customMap) {
		customMap[item.first].percent = (double)customMap[item.first].cnt / total;
		if (customMap[item.first].percent >= 0.05) customMap[item.first].candi = true;
		else customMap[item.first].candi = false;
	}

	vector<string> answer;

	for(const auto& item: customMap){
		// dbg
		//cout << item.first << ":" << item.second.cnt << ":" << item.second.percent << endl;

		if (item.second.candi) answer.push_back(item.first);
	}

	

	sort(answer.begin(), answer.end());

	return answer;
}