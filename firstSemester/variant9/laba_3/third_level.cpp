#include <iostream>
#include <cmath>
using namespace std;
double y(double x) 
{
	return (1 + x * x) / 2 * atan(x) - x / 2;
}

double s(double x, double eps, int& k) 
{
	double sum = 0, w = -x;  k = 0;
	do
	{
		k++;
		w *= -x * x;
		sum += w / (4 * k * k - 1);
	} while (fabs(w / (4 * k * k - 1)) > eps);
	return sum;
}
int main() {
	double x, a, b, h, eps;
	int k = 0;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "h = "; cin >> h;
	cout << "eps = "; cin >> eps;
	cout << "    x        s(x)        y(x)    |s(x)-y(x)|  kol\n";

	for (x = a; x <= b; x += h)
		printf("   %4.2lf   %9.6lf   %9.6lf   %9.6lf    %d\n",
			x, s(x, eps, k), y(x), fabs(s(x, eps, k) - y(x)), k);
	

	system("pause");
	return 0;
}