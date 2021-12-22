#include <iostream>
#include <cmath>

using namespace std;


double find_x(double z)
{
	double x;
	if (z > 0)
	{
		x = 1 / (z * (z + 2));
		cout << "z > 0  =>  x = " << x << endl;
	}
	else
	{
		x = 1 - pow(z, 3);
		cout << "z < 0 or z is 0 =>  x = " << x << endl;
	}
	return x;
}


double fi_x(double x, int i)
{
	double f;
	if (i == 0)
	{
		f = 2 * x;
		cout << "f(x) = 2x = " << f << endl;
	}
	if (i == 1)
	{
		f = x * x;
		cout << "f(x) = x^2 = " << f << endl;
	}
	if (i == 2)
	{
		f = x / 3;
		cout << "f(x) = x / 3 = " << f << endl;
	}
	return f;
}


int main()
{
	double z, x, a, b;
	cout << "Enter Z: ";
	cin >> z;
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;

	x = find_x(z);
	cout << "------------------------" << endl;

	double numerator = (2.5 * a * exp(-3 * x) - 4 * b * x * x);

	for (int i = 0; i < 3; i++)
	{
		double denominator = log(fabs(x)) + fi_x(x, i);
		if (denominator == 0)
		{
			cout << "Impossible operation: division by zero (denominator of function Y is 0)";
		}
		else
		{
			cout << "y = " << (numerator / denominator) << endl;
		}
		cout << "------------------------" << endl;
	}

}