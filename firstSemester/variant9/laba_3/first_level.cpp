#include <iostream>
#include <cmath>
using namespace std;

int main1() {
	double x, y, s, a, b, h, w;
	int n, k;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "h = "; cin >> h;
	cout << "n = "; cin >> n;
	cout << "    x        s(x)        y(x)    |s(x)-y(x)|\n";

	for (x = a; x <= b; x += h) 
	{
		y= (1 + x * x) / 2 * atan(x) - x / 2;
		s = 0; w = -x;
		for (k = 1; k <= n; k++) 
		{
			w *= -x * x;
			s += w/(4*k*k-1);
		}
		
		printf("   %4.2lf   %9.6lf   %9.6lf   %9.6lf\n",
			x, s, y, fabs(s - y));
	}

	system("pause");
	return 0;
}