#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<stack>

using namespace std;

/***
( 나오면 연산자 스택에 push
) 나오면 ( 나올때 까지 계산하고 pop한다.
연산자 나오면 우선순위가 자기보다 작은게 나올 때까지 연산한다.
이후 연산자 push
숫자는 숫자 스택에 push
마지막으로 남은 숫자와 op를 계산

-----연산 과정-----
1. 숫자를 2개 뽑는다
2. op를 1개 뽑는다
3. 계산하고 결과값을 push한다.
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