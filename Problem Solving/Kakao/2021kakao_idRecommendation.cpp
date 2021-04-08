/*
* problem: https://programmers.co.kr/learn/courses/30/lessons/72410
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

// function pre-defined
string solution(string new_id);


int main(void)
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
	cout << solution("z-+.^.") << endl;
	cout << solution("=.=") << endl;
	cout << solution("123_.def") << endl;
	cout << solution("abcdefghijklmn.p") << endl;

	return 0;
}

string solution(string new_id) {
	string answer = "";

	// step1
	
	for (int i = 0; i < new_id.size(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	// step2
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'a' && new_id[i] <= 'z') continue;
		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')continue;
		if (new_id[i] >= '0' && new_id[i] <= '9')continue;
		new_id.erase(new_id.begin() + i);
		if (new_id.empty())break;
		i--;
	}
	// step3
	if (new_id.size() > 1) {
		char before = new_id[0];
		for (int i = 1; i < new_id.size(); i++) {
			if (before == '.' && before == new_id[i]) {
				new_id.erase(new_id.begin() + i);
				if (new_id.empty())break;
				i--;
			}
			before = new_id[i];
		}
	}
	// step4
	if (!new_id.empty())
		if (new_id[0] == '.')new_id.erase(new_id.begin());
	if (!new_id.empty())
		if (new_id.back() == '.')new_id.erase(new_id.end());
	// step5
	if (new_id.empty())new_id = "a";
	// step6
	if (new_id.size() >= 16) {
		new_id = new_id.substr(0, 15);
	}
	if (!new_id.empty())
		if (new_id.back() == '.')new_id.pop_back();
	// step7
	while (new_id.size() < 3)
		new_id.push_back(new_id.back());

	answer = new_id;

	return answer;
}