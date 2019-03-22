#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;

int main()
{
	int n;
	string a, b;
	cin >> n>>a >> b;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])continue;
		cout << "Deletion failed"<<endl;
		return 0;
	}
	cout << "Deletion succeeded"<<endl;
	return 0;

	if (n % 2 == 0) {

	}
}
