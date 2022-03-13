#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double PI = acos(-1);
double eps = 1e-7;
int k;


double sum(double x) {
	double s, multiple;
	s = 0;
	multiple = 1000;
	k = 1;
	while (abs(multiple) >= eps) {
		multiple = pow(x, k) * cos(k * PI / 3) / k;
		s += multiple;
		k++;
	}
	return s;
}

void fun(double a, double b, double h) {
	double x, y, s;
	cout << setw(20) << "x" << setw(20) << "operations count" << setw(20) << "S(x)" << setw(20) << "Y(X)" << setw(20) << "|S(X) - Y(X)|\n";
	for (x = a; x <= b; x += h) {
		y = -0.5 * log(1 - 2 * x * cos(PI / 3) + x * x);
		s = sum(x);
		cout << setw(20) << x << setw(20) << k - 1 << setw(20) << s << setw(20) << y << setw(20) << abs(y - s) << '\n';
	}
}

int main() {
	double a, b, h;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "h = "; cin >> h;
	cout << "e = "; cin >> eps;
	fun(a, b, h);
	system("pause");
	return 0;
}

