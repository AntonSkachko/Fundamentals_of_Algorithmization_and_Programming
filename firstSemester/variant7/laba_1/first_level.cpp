#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);

int main() {
	double z1, z2; // result
	double a, b; // variables
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;

	double x, y; // additional variables
	
	x = 2 * pow(sin(3 * PI - 2 * a), 2);
	y = pow(cos(5 * PI + 2 * a), 2);

	z1 = x * y;
	cout << "Result 1: " << z1 << endl;

	z2 = 1 / .4 - 1 / .4 * sin(5 / .2 * PI - 8 * a);
	cout << "Result 2: " << z2 << endl;

	return 0;
}