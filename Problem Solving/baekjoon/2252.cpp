//topological sort
//priority queue

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	int N;	//<=32,000	�л���
	int M;	//<=100,000	Ű �� Ƚ��

	cin >> N;
	cin >> M;

	int arr[35000];
	vector<int> vec[35000];

	for (int i = 0; i < 35000; i++) {
		arr[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int A, B;

		cin >> A;
		cin >> B;	//A�� B�տ� �����Ѵ�.
		
		arr[B]++;
		vec[A].push_back(B);

	}

	queue<int> q;
	//0���� �ֵ��� ť�� �ִ´�
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			q.push(i);
			arr[i]--;
		}
	}

	while (!q.empty()) {
		//�Ѹ� ���鼭 ��� ���������� ����ġ�� �ϳ��� ����
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < vec[cur].size(); i++) {
			
			arr[vec[cur][i]]--;
			//0������� ť�� �ִ´�.
			if (arr[vec[cur][i]] == 0) {
				q.push(vec[cur][i]);
				arr[vec[cur][i]]--;
			}
		}
	}

	cout << endl;
}