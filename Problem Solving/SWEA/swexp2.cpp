/********************
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14tDX6AFgCFAYD&categoryId=AV14tDX6AFgCFAYD&categoryType=CODE
���⹮��
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
			if(token == "("){				//(�� ��� push
				operand.push({ "(",0 });
			}
			else if (token == ")") {		//)�� ��� operand ( ���� ���
				while (operand.top().op != "(") {
					calc();
				}
				operand.pop();	//( pop
			}
			else if(token=="+"||token=="-"||token=="*"||token=="/"){
				int prior;
				if (token == "+" || token == "-") {	//op�� push
					prior = 1;
				}
				else if (token == "*" || token == "/") {	//op�� push
					prior = 2;
				}
				while (!operand.empty() && prior <= operand.top().prior) {	
					//op�� ������� ���� && newop�� �켱������ op.top���� �۾ƾ���
					calc();	//op�ϳ� pop�Ǹ鼭 ���.
				}
				
				operand.push({ token,prior });
			}
			else {
				int temp;
				temp = stoi(token);
				num.push(temp);		//num�� push.
			}
		}

		while (!operand.empty()) {
			calc();		//op�� ���������� ����
		}
	
		while (!num.empty()) {
			cout <<"#"<<test_case<<" "<< num.top() << endl;
			num.pop();
		}

	}


	return 0;
}

void calc()	//����2�� op�Ѱ� �̾Ƽ� �ѹ��� ����
{
	int a, b, res;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();		//���� 2�� pop
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
	num.push(res);	//��� push
}
