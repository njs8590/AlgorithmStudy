#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	vector<string> phone_book = { "1442","123","1235","567","88" };

	bool answer = true;

	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = i; j < phone_book.size(); j++) {
			if (i == j)continue;
			if (phone_book[j].find(phone_book[i]) == 0) {
				answer = false;
				return answer;
			}
		}
	}	//ȿ��������

	
	return answer;

}

//sorting �� �� phone_book[i] == phone_book[i+1] �� ��
//���ԵǾ��ִ°�쿡�� �ٷ� return falses