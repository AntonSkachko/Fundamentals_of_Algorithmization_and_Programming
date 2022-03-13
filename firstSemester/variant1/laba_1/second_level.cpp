#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double z1, z2, a, b, x, y;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;

	x = cos(a) + 1 - 2 * pow(sin(2 * a), 2);
	if (x == 0) {
		cout << "EROR!";
		return 0;
	}
	y = sin(2 * a) + sin(5 * a) - sin(3 * a);

	z1 = y / x;
	z2 = 2 * sin(a);
	
	cout << "Result 1: " << z1 << endl;
	cout << "Result 2: " << z2 << endl;

	return 0;
}