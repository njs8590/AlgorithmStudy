/*
* @problem: https://programmers.co.kr/learn/courses/30/lessons/72411
* 코스요리 메뉴는 단품메뉴 최소 2개, 2번 이상 주문이력
* input: 주문이력, 코스메뉴를 구성하는 단품 수
* return: 코스메뉴 (오름차순)
*/

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

// function pre-defined
vector<string> solution(vector<string> orders, vector<int> course);
void makePair(string order, string candi, int idx);
void printMap();
void makeMenu(vector<int> course);

//global var
map<string, int> menuMap;
int course_max[11];
vector<string> answer;

int main(void)
{
	vector<string> orders =
		// { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	// { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
	{ "XYZ", "XWY", "WXA" };
	vector<int> course = { 2,3,4 };
	solution(orders, course);

	return 0;
}

void makePair(string order, string candi, int idx) {
	for (int i = idx; i < order.size(); i++) {
		candi.push_back(order[i]);
		if(candi.size()>=2)menuMap[candi]++;
		makePair(order, candi, i + 1);
		candi.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	

	for (string& order : orders) {
		sort(order.begin(), order.end());
		makePair(order, "", 0);
	}

	//printMap();
	makeMenu(course);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return answer;
}

void printMap() {
	for (auto temp : menuMap) {
		if(temp.second>1)
		cout << temp.first << ":" << temp.second << endl;
	}
}

void makeMenu(vector<int> course) {
	for (auto menu : menuMap) {
		int curCourse = menu.first.size(); // 단품메뉴 개수
		string curMenu = menu.first;
		int curMenuCount = menu.second;

		if (curMenuCount < 2)continue;

		for (int i = 0; i < course.size(); i++) {
			if (curCourse == course[i]) {
				// 조합메뉴 최대주문수 갱신
				if (course_max[curCourse] < curMenuCount) course_max[curCourse] = curMenuCount;
			}
		}
	}

	for (auto menu : menuMap) {
		int curCourse = menu.first.size(); // 단품메뉴 개수
		string curMenu = menu.first;
		int curMenuCount = menu.second;

		for (int i = 0; i < course.size(); i++) {
			if (curCourse == course[i] && curMenuCount == course_max[curCourse]) {
				answer.push_back(curMenu);
			}
		}
	}
}