#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double y, x, z, q{}, a;
	int w;
	cout << "Enter z: "; cin >> z;
	cout << "Enter a: "; cin >> a;

	if (z < 1) {
		x = z * z;
		cout << "z < 1\n x = z * z\n";
	}
	else {
		x = z + 1;
		cout << "z >= 1\n x = z + 1\n";
	}

	cout << "What function do you want to see?\n";
	cout << "1 - 2 * x, 2 - x * x, 3 - x / 3\n";
	cin >> w;

	switch (w) {
		case 1:
			q = x * 2;
			break;
		case 2:
			q = x * x; 
			break;
		case 3:
			q = x / 3;
			break;
	}

	y = a * log(1 + pow(x, 1. / 5)) + pow(cos(q + 1), 2);

	cout << "Result: " << y;
	return 0;
}