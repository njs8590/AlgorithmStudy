/***************
https://www.acmicpc.net/problem/14891
��Ϲ���
4���� ��Ϲ���
��Ϲ����� ���� N�� 0, S�� 1
12�ú��� �ð�������� ���°� input
�´��� ���� �ٸ��� ���� �ݴ�������� ȸ��
��Ϲ�ȣ, ȸ������(�ð�1, �ݽð�-1) input

****************/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> t1, t2, t3, t4;	//8�� ����
//0���� 12��, 2��/6���� �´�Ե�.

int K; //ȸ�� Ƚ��
int t_num, t_dir;

int main()
{
	int temp;
	
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		t1.push_back(temp);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		t2.push_back(temp);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		t3.push_back(temp);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		t4.push_back(temp);
	}
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &t_num, &t_dir);
		
		//�� ��� ȸ������
		int rotate_check[3] = { 0, };	//1-2, 2-3, 3-4

		if (t1[2] != t2[6]) {
			rotate_check[0] = 1;	//ȸ��o
		}
		if (t2[2] != t3[6]) {
			rotate_check[1] = 1;
		}
		if (t3[2] != t4[6]) {
			rotate_check[2] = 1;
		}
		
		//�� ��� ȸ������
		int rotate_dir[5] = { 0, };
		rotate_dir[t_num] = t_dir;

		if (t_num == 1) {
			if (rotate_check[0] == 1) {
				for (int i = 2; i <= 4; i++) {
					rotate_dir[i] = rotate_dir[i] - rotate_dir[i - 1];
				}
			}
		}
		else if (t_num == 2) {
			if (rotate_check[0] == 1) {
				rotate_dir[t_num - 1] = rotate_dir[t_num - 1] - rotate_dir[t_num];
			}
			if (rotate_check[1] == 1) {
				for (int i = 3; i <= 4; i++) {
					rotate_dir[i] = rotate_dir[i] - rotate_dir[i - 1];
				}
			}
		}
		else if (t_num == 3) {
			if (rotate_check[1] == 1) {
				for (int i = 2; i >= 1; i--) {
					rotate_dir[i] = rotate_dir[i] - rotate_dir[i + 1];
				}
			}
			if (rotate_check[2] == 1) {
				rotate_dir[t_num + 1] = rotate_dir[t_num + 1] - rotate_dir[t_num];
			}
		}
		else if (t_num == 4) {
			if (rotate_check[2] == 1) {
				for (int i = 3; i >= 1; i--) {
					rotate_dir[i] = rotate_dir[i] - rotate_dir[i + 1];
				}
			}
		}

		//��� ȸ��
		if (rotate_dir[1] == 1) {
			int back = t1[t1.size() - 1];
			t1.pop_back();
			t1.insert(t1.begin(), back);
		}
		else if (rotate_dir[1] == -1) {
			int back = t1.front();
			t1.erase(t1.begin());
			t1.push_back(back);
		}

		if (rotate_dir[2] == 1) {
			int back = t2[t2.size() - 1];
			t2.pop_back();
			t2.insert(t2.begin(), back);
		}
		else if (rotate_dir[2] == -1) {
			int back = t2.front();
			t2.erase(t2.begin());
			t2.push_back(back);
		}

		if (rotate_dir[3] == 1) {
			int back = t3[t3.size() - 1];
			t3.pop_back();
			t3.insert(t3.begin(), back);
		}
		else if (rotate_dir[3] == -1) {
			int back = t3.front();
			t3.erase(t3.begin());
			t3.push_back(back);
		}

		if (rotate_dir[4] == 1) {
			int back = t4[t4.size() - 1];
			t4.pop_back();
			t4.insert(t4.begin(), back);
		}
		else if (rotate_dir[4] == -1) {
			int back = t4.front();
			t4.erase(t4.begin());
			t4.push_back(back);
		}

	}

	//�������
	int answer = 0;

	if (t1[0] == 1) {
		answer += 1;
	}
	if (t2[0] == 1) {
		answer += 2;
	}
	if (t3[0] == 1) {
		answer += 4;
	}
	if (t4[0] == 1) {
		answer += 8;
	}

	printf("%d\n", answer);
}