#include<iostream>

using namespace std;

int normal_fibo(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return normal_fibo(n - 2) + normal_fibo(n - 1);
}

int main(void)
{
	cout << normal_fibo(2) << endl;
	return 0;
}