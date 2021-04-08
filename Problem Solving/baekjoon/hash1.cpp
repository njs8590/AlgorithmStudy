#include <string>
#include <vector>
#include<map>
#include<iostream>
#include<stdio.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	

	return answer;
}

int main()
{

	vector<string> participant = { "marina", "josipa", "filipa", "vinko", "filipa"};
	vector<string> completion = { "josipa", "filipa", "marina", "nikola" };

	map<string, int> m;

	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]]++;	
	}

	cout << m.size() << endl;

	cout << m["kiki"] << endl;

	for (int i = 0; i < completion.size(); i++) {
		if (--m[completion[i]] != 0)
			cout<< completion[i]<<endl;
	}
	
	for (int i = 0; i < participant.size(); i++) {
		if (m[participant[i]] == 1) {
			cout << participant[i] << endl;
		}
	}

	return 0;
}

//sorting 한 후 participant[i] == completion[i] 를 비교 다르면 바로 리턴