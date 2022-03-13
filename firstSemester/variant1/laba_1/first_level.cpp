#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);

int main() {
	int z1, z2, a, b, x, y;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;

	x = pow(cos(5 * PI + 2 * a), 2) * 2;
	z1 = pow(sin(3 * PI - 2 * a), 2) * x;


	z2 = 1. / 4 - 1. / 4 * sin(5. / 2 * PI - 8 * a);

	cout << "Result 1: " << z1 << endl;
	cout << "Result 2: " << z2 << endl;

	return 0;

}