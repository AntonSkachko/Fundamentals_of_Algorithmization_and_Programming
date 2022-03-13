#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double k, z, x, y;

	cout << "Enter k: "; cin >> k;
	cout << "Enter z: "; cin >> z;

	if (k < 1) {
		x = k * z * z * z;

		cout << "k < 1\n" << "x = k * z * z * z\n";
	}
	else {
		x = z * (z + 1);
		cout << "k >= 1\n" << "x = z * (z + 1)\n";
	}

	y = pow(log(1 + x * x) + cos(x + 1), exp(k * x));

	cout << "Resutl: " << y;

	return 0; 
}