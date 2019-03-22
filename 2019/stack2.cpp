#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	vector<int> priorities = { 2,1,3,2 };
	queue<int> q;

	for (int i = 0; i < priorities.size(); i++) {
		q.push(priorities[i]);
	}

	int location=2;
	int max_index = 0;

	bool find_answer = true;
	int answer = 1;
	bool update = true;

	while (find_answer||q.size()>1) {
		update = true;
		int cur = q.front();
		//cout << cur <<" "<<location<< endl;
		//system("pause");

		for (int i = 1; i < q.size(); i++) {
			if (priorities[i] > cur) {
				max_index = i;
				update = false;	//¸ø»ÌÀ½
			}
		}

		if (!update) {	//¸ø»ÌÀ½
			q.pop();
			q.push(cur);
			if (location == 0) {
				location = q.size()-1;
			}
			else {
				location--;
			}
		}
		else if (update) {	//»ÌÀ½
			//cout << "»Ç¤³¾Ñ´Ù";
			q.pop();
			priorities[max_index] = -1;
			if (location == 0) {
				find_answer = true;
				break;
			}
			else {
				location--;
				answer++;
			}
		}
	}
	cout << answer << endl;


	return 0;
}
