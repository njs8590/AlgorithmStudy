//topological sort
//priority queue

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	int N;	//<=32,000	학생수
	int M;	//<=100,000	키 비교 횟수

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
		cin >> B;	//A가 B앞에 서야한다.
		
		arr[B]++;
		vec[A].push_back(B);

	}

	queue<int> q;
	//0순위 애들을 큐에 넣는다
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			q.push(i);
			arr[i]--;
		}
	}

	while (!q.empty()) {
		//한명씩 빼면서 모든 선행조건의 가중치를 하나씩 감소
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < vec[cur].size(); i++) {
			
			arr[vec[cur][i]]--;
			//0순위라면 큐에 넣는다.
			if (arr[vec[cur][i]] == 0) {
				q.push(vec[cur][i]);
				arr[vec[cur][i]]--;
			}
		}
	}

	cout << endl;
}