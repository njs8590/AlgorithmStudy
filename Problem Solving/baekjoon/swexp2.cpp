/********************
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14tDX6AFgCFAYD&categoryId=AV14tDX6AFgCFAYD&categoryType=CODE
계산기문제
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
*********************/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;

//typedf
typedef struct oper {
	string op;
	int prior;
}oper;

//func
void calc();

//global var
stack<int> num;
stack<oper> operand;

int main()
{
	int T;
	//cin >> T;
	T = 10;

	for (int test_case = 1; test_case <= T; test_case++) {

		int test_size;
		scanf("%d", &test_size);

		string line;
		cin >> line;
		
		string token;

		for(int i=0;i<test_size;i++){

			token = line.at(i);
			if(token == "("){				//(일 경우 push
				operand.push({ "(",0 });
			}
			else if (token == ")") {		//)일 경우 operand ( 까지 계산
				while (operand.top().op != "(") {
					calc();
				}
				operand.pop();	//( pop
			}
			else if(token=="+"||token=="-"||token=="*"||token=="/"){
				int prior;
				if (token == "+" || token == "-") {	//op에 push
					prior = 1;
				}
				else if (token == "*" || token == "/") {	//op에 push
					prior = 2;
				}
				while (!operand.empty() && prior <= operand.top().prior) {	
					//op가 비어있지 않음 && newop의 우선순위가 op.top보다 작아야함
					calc();	//op하나 pop되면서 계산.
				}
				
				operand.push({ token,prior });
			}
			else {
				int temp;
				temp = stoi(token);
				num.push(temp);		//num에 push.
			}
		}

		while (!operand.empty()) {
			calc();		//op가 남아있으면 연산
		}
	
		while (!num.empty()) {
			cout <<"#"<<test_case<<" "<< num.top() << endl;
			num.pop();
		}

	}


	return 0;
}

void calc()	//숫자2개 op한개 뽑아서 한번만 연산
{
	int a, b, res;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();		//숫자 2개 pop
	string op;
	op = operand.top().op;
	operand.pop();	//op pop

	if (op == "+") {
		res = a + b;
	}
	else if (op == "-") {
		res = a - b;
	}
	else if (op == "*") {
		res = a * b;
	}
	else if (op == "/") {
		res = a / b;
	}
	num.push(res);	//결과 push
}
