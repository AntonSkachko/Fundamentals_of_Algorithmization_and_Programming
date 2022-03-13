#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a, b, h, x, y, n = 0;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	cout << "Enter h: "; cin >> h;

	for (x = a; x < b; x += h) {
		n++;
		y = 2 * sin(x) / pow(1 - x, 2);
		cout << n << setw(10) << x << setw(20) << y << endl;
	}

	return 0;
}