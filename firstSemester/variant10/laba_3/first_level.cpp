#include <iostream>
#include <cmath>
using namespace std;

double y(double x)
{
	return (exp(x) + exp(-x)) / 2.0;
}

double s(double x, double eps, int& k)
{
	double sum = 0, w = -x; k = 0;
	do
	{
		k++;
		w *= x * x / ((2 * k - 1) * 2 * k);
		sum += w;
	} while (fabs(w) > eps);
	return sum;
}
int main() {
	double x, a, b, h, eps;
	int k = 0;
	cout « "a = "; cin » a;
	cout « "b = "; cin » b;
	cout « "h = "; cin » h;
	cout « "eps = "; cin » eps;
	cout « " x s(x) y(x) |s(x)-y(x)| kol\n";

	for (x = a; x <= b; x += h)
		printf("     %4.2lf      %9.6lf      %9.6lf      %9.6lf    %d\n",
			x, s(x, eps, k), y(x), fabs(s(x, eps, k) - y(x)), k);


	system("pause");
	return 0;
}