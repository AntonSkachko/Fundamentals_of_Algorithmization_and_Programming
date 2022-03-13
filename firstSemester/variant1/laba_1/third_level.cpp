#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);

int main() {
	double t, x, y, z, a, b;

	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "Enter z: "; cin >> z;

	a = 0.5 + sin(y) * sin(y);
	b = 3 - z * z / 5;

	if (a == 0 || b == 0) {
		cout << "Error";
		return 0;
	}

	t = 2 * cos(x - PI / 6) / a * (1 + z * z / b);
	cout << "Result: " << t;

	return 0;
}