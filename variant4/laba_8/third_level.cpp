#include<iostream>
using namespace std;
int fib(int n)       //функция без рекурсии
{
	if (n == 0) return 0;
	int a = 1, b = 0, k;
	for (int i = 1; i <= n; i++) 
	{
		k = b + a;
		a = b;
		b = k;
	}
	return k;
}
int f(int n)  // рекурсивная функция
{
	if (n <2) return n;
	return f(n - 1) + f(n - 2);
}
int main()
{
	int n;
	cout << "n = ";  cin >> n;
	cout << "Fb1(" << n << ") = " << fib(n) << endl;
	cout << "Fb2(" << n << ") = " << f(n) << endl;
	return 0;
}