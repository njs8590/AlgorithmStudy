#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<stack>

using namespace std;

/***
( ������ ������ ���ÿ� push
) ������ ( ���ö� ���� ����ϰ� pop�Ѵ�.
������ ������ �켱������ �ڱ⺸�� ������ ���� ������ �����Ѵ�.
���� ������ push
���ڴ� ���� ���ÿ� push
���������� ���� ���ڿ� op�� ���

-----���� ����-----
1. ���ڸ� 2�� �̴´�
2. op�� 1�� �̴´�
3. ����ϰ� ������� push�Ѵ�.
***/

typedef struct oper {
	string op;
	int prior;
}oper;

void calc();

stack<int> num;
stack<oper> operand;

int main()
{
	
	return 0;
}