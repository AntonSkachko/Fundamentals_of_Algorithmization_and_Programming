#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x, y, z; // variables
	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "Enter z: "; cin >> z;

	double a, b; // additional variables
	
	a = x + 3 * fabs(x - y) + x * x;
	b = fabs(x - y) * z + x * x;

	cout << "Result: " << 5 * atan(x) - 1 / .4 * acos(x) * a / b;

	return 0;
}