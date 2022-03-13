#include <iostream>

using namespace std;


int factorial(int k)
{	 
	if (k == 0 || k == 1)
	{
		return 1;
	}
	int f = 1;
	for (int i = 2; i <= k; i++)
	{
		f *= i;
	}
	return f;
}


double S(double x, double n)
{
	double s = 0;
	for (int k = 0; k <= n; k++)
	{
		s += (k * k + 1) * pow(0.5 * x, k) / factorial(k);
	}
	return s;
}


double Y(double x)
{
	double y = (x * x / 4 + x / 2 + 1) * exp(0.5 * x);
	return y;
}

int main()
{
	double a, b, h, n;
	
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;
	cout << "Enter H: ";
	cin >> h;
	cout << "Enter N: ";
	cin >> n;
	
	cout << "-----------------------------------------------" << endl;
	cout << "Y(x)		S(x)		|Y(x) - S(x)|" << endl;

	for (double x = a; x <= b; x += h)
	{
		double s = S(x, n);
		double y = Y(x);

		cout << y << "		" << s << "		 " << fabs(y - s) << endl;
	}
}
