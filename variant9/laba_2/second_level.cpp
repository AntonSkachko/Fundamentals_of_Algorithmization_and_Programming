#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double x, y, z, a, b, c, d, func;

	cout << "Z =  ";	cin >> z;
	cout << "A = ";		cin >> a;
	cout << "B =  ";	cin >> b;

	int function;
	cout << "1. f(x) = 2*x\n "<<"2. f(x) = x*x\n"<<"3. f(x) = x/3\n"<<"Выберите функцию: ";
	cin >> function;

	if (z <= 0)		x = z * z / 2;
	        else	x = sqrt(z);
	

	switch (function)
	{
	  case 1:		func = 2 * x;	cout << "f(x) = 2*x";	break;
	  case 2:		func = x * x;	cout << "f(x) = x*x";	break;
	  case 3:		func = x / 3;	cout << "f(x) = x/3";	break;
	}

	c = b * function / cos(x);
	d = log(fabs(tan(x / 2)));
	y = c + a * d;

	cout << "   Result = " << y << endl;

	system ("pause");
	return 0;
}