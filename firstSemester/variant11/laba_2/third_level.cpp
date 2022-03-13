#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, a;
	
	cout << "Enter X:  ";
	cin >> x;
	cout << "Enter Y:  ";
	cin >> y;
	cout << "Enter A:  ";
	cin >> a;

	cout << "Result is ";
	if (a == 0 )
	{
		cout << fmax(fmax(x, y), a);
	}
	else
	{
		if (a > 0)
		{
			cout << (fabs(x - y) + y * (x + pow(a, 1 / 3.)));
		}
		else
		{
			cout << (fmin(x * x, y * y) + a);
		}
	}
}