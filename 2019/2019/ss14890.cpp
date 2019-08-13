/******************
https://www.acmicpc.net/problem/14890
경사로
N * N 그래프
그래프 성분 = 그 곳의 높이
경사로의 길이 L : L만큼 그래프를 차지함
경사로는 낮은 칸에 놓음
높낮이 차이가 1이 아니면 경사로 x
낮은지점이 연속되어야함
1. 진행하다가 높낮이가 다른경우 발생
2. 경사로를 놓을 수 있는지?
3. 갈 곳이 높다면 이전 길에 경사로 배치,
4. 갈 곳이 낮다면 다음 길에 경사로 배치
5. 끝까지 도착하면 갈 수 있는 경로.
그래프를 행, 열 한줄 씩 따서 -> 진행가능한지?

******************/

#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//func
bool move();

//global var
int N; //그래프 크기
int L; //경사로 길이
int graph[101][101];
int line[101];
int answer = 0;


int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	//한줄 따기 - 가로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			line[j] = graph[i][j];
		}
		if (move() == true) {
				answer++;
		}
	}
	//한줄 따기 - 세로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			line[j] = graph[j][i];
		}
		if (move() == true) {
			answer++;
		}
	}
	printf("%d\n", answer);
}

bool move() {

	int cur = 0;
	int count_L = 1;
	int visited[101] = { 0, };
	visited[0] = 1;

	bool is_updated = true;
	while (is_updated==true) {
		is_updated = false;
		int next = cur + 1;

		//높낮이가 같은경우
		if (line[next] == line[cur]) {
			//진행
			cur = next;
			is_updated = true;
			if (visited[cur] == 0) {
				count_L++;
				visited[cur] = 1;
			}
		}

		//높이차가 2이상인 경우
		else if (abs(line[next] - line[cur]) >= 2) {
			//종료
		}

		//가려는 길이 더 높은경우
		else if (line[next] > line[cur]) {
			if (count_L >= L) {
				cur = next;
				is_updated = true;
				count_L = 1;
			}
		}

		//가려는 길이 더 낮은 경우
		else if (line[next] < line[cur]) {
			//지나갈 길에 경사로를 세울 수 있는지
			count_L = 0;
			for (int i = 0; i < L; i++) {
				if (line[next] == line[next+i]) {
					visited[next+i] = 1;
					count_L++;
				}
			}
			if (count_L >= L) {
				
				is_updated = true;
				cur = next;
				count_L = 0;
			}
		}
		//마지막 칸에 도착한경우
		if (cur == N - 1) {
			return true;
		}
	}

	return false;
}