#include <iostream>
#include <map>

using namespace std;

double e = 0.0001;


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


// I don't know how to return 2 values, so I did this
double S(double x)
{	
	double s = 0;
	double new_s = 10e6;
	int k = 0;
	while (new_s > e)
	{
		new_s = (k * k + 1) * pow(0.5 * x, k) / factorial(k);
		s += new_s;
		k++;
	}
	if (k != 0)
	{
		k--;
	}
	cout << s << "		" << k << "			"; ///This one
	return s;
}


double Y(double x)
{
	double y = (x * x / 4 + x / 2 + 1) * exp(0.5 * x);
	return y;
}

int main()
{
	double a, b, h;

	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;
	cout << "Enter H: ";
	cin >> h;

	cout << "-------------------------------------------------------" << endl;
	cout << "S(x)		Iteration		Y(x)		|Y(x) - S(x)|" << endl;

	for (double x = a; x <= b; x += h)
	{
		double y = Y(x);
		double s = S(x);
		cout << y << "		" << fabs(y - s) << endl;
	}
}
