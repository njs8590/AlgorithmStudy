/********************
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWngfZVa9XwDFAQU&categoryId=AWngfZVa9XwDFAQU&categoryType=CODE
창용 마을 무리의 개수
N명의 사람이 산다
사람에게 번호가 있다. 1~N
두 사람이 서로 아는 관계, 몇 사람을 거쳐서 알 수 있는 관계라면 같은 무리.
알고있는 관계의 수 M

*********************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

//typedf

//func
void init();

//global var
int N, M;
int team[101] = { 0, };
int find_answer[101] = { 0, };
int team_count = 1;
int answer = 0;

int main()
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		init();

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int p1, p2;

			cin >> p1 >> p2;

			if (team[p1]==0 && team[p2]==0) {
				team[p1] = team_count;
				team[p2] = team_count++;
				find_answer[team_count] = 1;
			}
			else if (team[p1] != 0 && team[p2] == 0) {
				team[p2] = team[p1];
			}
			else if (team[p1] == 0 && team[p2] != 0) {
				team[p2] = team[p1];
			}
			else if (team[p1] != 0 && team[p2] != 0) {
				if (team[p1] == team[p2]) continue;

				int team_candi;
				int change_candi;

				if (team[p1] < team[p2]) {
					team_candi = team[p1];
					change_candi = team[p2];
				}
				else {
					team_candi = team[p2];
					change_candi = team[p1];
				}

				team[p1] = team_candi;
				team[p2] = team_candi;

				for (int j = 0; j <= N; j++) {
					if (team[j] == change_candi) {
						team[j] = team_candi;
					}
				}
				find_answer[change_candi] = 0;
				
			}
			
		}
		for (int i = 1; i <= N; i++) {
			if (find_answer[i] != 0) {
				answer++;
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}


	return 0;
}

void init()
{
	for (int i = 0; i < 101; i++) {
		team[i] = 0;
		find_answer[i] = 0;
	}
	team_count = 1;
	answer = 0;
}