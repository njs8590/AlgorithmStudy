/***********
°¨½Ã
graph Å©±â N*M
CCTV´Â K°³
CCTV Á¾·ù 5°³
0: -> , 1: <--> , 2: ¤¤ , 3: ¤Ç, 4: +
graph : 0 ºóÄ­, 6 º®, 1~5 CCTV

************/


#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int N, M;
int graph[8][8];

typedef struct pos {
	int y;
	int x;
	int type;
}pos;

void dfs(pos cur_cctv, int cctv_index, int d);
void graph_copy(int from[8][8], int to[8][8]);
void graph_check(pos cur_pos, int d);
void print();

vector<pos> cctv;
int answer = 64;

int type_dir[5] = { 4,2,4,4,1 };

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			if (1 <= graph[i][j] && graph[i][j] <= 5) {
				cctv.push_back({ i,j,graph[i][j] });	//cctv À§Ä¡, Å¸ÀÔ
			}
		}
	}
	//cctv.push_back({ -2,-2,-2});
	//print();
	if(cctv.size()!=0)
	for (int d = 0; d < 4; d++) {
		int copy[8][8];
		graph_copy(graph, copy);
		dfs(cctv[0], 0, d);
		graph_copy(copy, graph);
	}
	else if (cctv.size() == 0) {
		int candi = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 0) {
					candi++;
				}
			}
		}
		if (answer > candi) {
			answer = candi;
		}
	}
	printf("%d\n", answer);

}

void dfs(pos cur_cctv, int cctv_index, int d)
{
	//system("pause");
	
	int copy[8][8];

	//¸Ê¿¡ ±×¸®±â
	if (cur_cctv.type == 1) {
		if (d == 0) {
			graph_check(cur_cctv, 0);
		}
		else if (d == 1) {
			graph_check(cur_cctv, 1);
		}
		else if (d == 2) {
			graph_check(cur_cctv, 2);
		}
		else if (d == 3) {
			graph_check(cur_cctv, 3);
		}
		
	}
	else if (cur_cctv.type == 2) {
		if (d == 0||d==2) {//l
			graph_check(cur_cctv, 0);		//»ó
			graph_check(cur_cctv, 1);		//ÇÏ
		}
		else if (d == 1||d==3) {// <-->
			graph_check(cur_cctv, 2);		//ÁÂ
			graph_check(cur_cctv, 3);		//¿ì
		}
	}
	else if (cur_cctv.type == 3) {
		if (d == 0) {//¤¤
			graph_check(cur_cctv, 0);	//»ó
			graph_check(cur_cctv, 3);	//¿ì
		}
		else if (d == 1) {//-l
			graph_check(cur_cctv, 3);	//¿ì
			graph_check(cur_cctv, 1);	//ÇÏ
		}
		else if (d == 2) {//¤¡
			graph_check(cur_cctv, 1);	//ÇÏ
			graph_check(cur_cctv, 2);	//ÁÂ
		}
		else if (d == 3) {//_l
			graph_check(cur_cctv, 2);	//ÁÂ
			graph_check(cur_cctv, 0);	//»ó
		}
	}
	else if (cur_cctv.type == 4) {
		if (d == 0) {//¤Ç
			graph_check(cur_cctv, 0);	//»ó
			graph_check(cur_cctv, 3);	//¿ì
			graph_check(cur_cctv, 2);	//ÁÂ
		}
		else if (d == 1) {//¤¿
			graph_check(cur_cctv, 0);	//»ó
			graph_check(cur_cctv, 3);	//¿ì
			graph_check(cur_cctv, 1);	//ÇÏ
		}
		else if (d == 2) {//¤Ì
			graph_check(cur_cctv, 1);	//ÇÏ
			graph_check(cur_cctv, 2);	//ÁÂ
			graph_check(cur_cctv, 3);	//¿ì
		}
		else if (d == 3) {//¤Ã
			graph_check(cur_cctv, 2);	//ÁÂ
			graph_check(cur_cctv, 0);	//»ó
			graph_check(cur_cctv, 1);	//ÇÏ
		}
	}
	else if (cur_cctv.type == 5) {
		if (d == 0||d==1||d==2||d==3) {//+
			graph_check(cur_cctv, 0);	//»ó
			graph_check(cur_cctv, 1);	//ÇÏ
			graph_check(cur_cctv, 2);	//ÁÂ
			graph_check(cur_cctv, 3);	//¿ì
		}
	}
	
	

	//ºó°ø°£ count
	
	int candi=0;

	if (cctv_index == cctv.size()-1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 0) {
					candi++;
				}
			}
		}
		if (answer > candi) {
			answer = candi;
		}
	}
	//cout << candi << endl;
	

	//print();
	//cout << cctv[cctv_index].type << endl;

	for (int dir = 0; dir < 4; dir++) {
		
		if (cctv_index == cctv.size()-1) {
			break;
		}
	
		//backup
		graph_copy(graph, copy);
		//print();
		dfs(cctv[cctv_index+1], cctv_index+1, dir);
		//load
		graph_copy(copy, graph);
		//print();
	}

	return;
}

void graph_copy(int from[8][8], int to[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			to[i][j] = from[i][j];
		}
	}
}

void graph_check(pos cur_pos, int d) {
	graph[cur_pos.y][cur_pos.x] = -1;
	//»ó
	if (d == 0) {

		for (int y = cur_pos.y; y >= 0; y--) {
			if (graph[y][cur_pos.x] == 6)break;
			graph[y][cur_pos.x] = -1;
		}
	}
	//ÇÏ
	else if (d == 1) {
		for (int y = cur_pos.y; y<N; y++) {
			if (graph[y][cur_pos.x] == 6)break;
			graph[y][cur_pos.x] = -1;
		}
	}
	//ÁÂ
	else if (d == 2) {
		for (int x = cur_pos.x; x >= 0; x--) {
			if (graph[cur_pos.y][x] == 6)break;
			graph[cur_pos.y][x] = -1;
		}
	}
	//¿ì
	else if (d == 3) {
		for (int x = cur_pos.x; x <M; x++) {
			if (graph[cur_pos.y][x] == 6)break;
			graph[cur_pos.y][x] = -1;
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}