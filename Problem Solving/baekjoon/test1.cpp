#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
	string str = "((ab)3cde)2";
	string answer = "";
	stack<int> stk;	//head, tail

	for (int i = 0; i < str.size(); i++) {
		char temp = str.at(i);

		if (temp == '(') {
			stk.push(i);
		}
		if (temp == ')') {
			int head = stk.top();
			int tail = i;
			int count = atoi(&str.at(i + 1));
			stk.pop();
			for (int cnt = 0; cnt < count; cnt++) {
				for (int j = head+1; j < tail; j++) {
					if (str.at(j) >= 'a' && str.at(j) <= 'z') {
						cout << str.at(j);
					}
				}
			}
		}
	}

	
	return 0;
}