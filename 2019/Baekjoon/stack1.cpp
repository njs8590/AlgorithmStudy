#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main()
{
	//string arrangement = "()(((()())(())()))(())";
	stack<char> stk;
	int answer = 0;
	bool laser = false;	// '('

	for (int i = 0; i < arrangement.size(); i++) {
		char cur = arrangement.at(i);
		if (cur == ')') {
			if (laser) {	//이전이 '('
				stk.pop();
				//현재 스택 갯수만큼 answer에 추가
				answer += stk.size();
				laser = false;
			}
			else if (!laser) {
				stk.pop();
				answer += 1;
			}
		}
		else if (cur == '(') {
			stk.push(cur);
			laser = true;
		}
	}

	//cout << answer << endl;

	return answer;
}
