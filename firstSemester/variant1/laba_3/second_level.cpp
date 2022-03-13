#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, fac = 1;
	double a, b, h, y, s = 0, sum;
	cout << "Enter a:"; cin >> a;
	cout << "Enter b:"; cin >> b;
	cout << "Enter h:"; cin >> h; 
	cout << "Enter n:"; cin >> n;

	cout <<setw(15) << "y" << setw(15) << "s" << setw(15) << "|y - s|" << endl;

	for (double x = a; x < b; x += h) {
		for (int k = 0; k < n; k++) { // Error
			for (int j = 1; j < 2 * k + 1; j++) {
				fac *= j;
			}
			s += pow(-1, k) * pow(x, 2 * k + 1) / fac;
		}
		y = sin(x);
		sum = abs(y - s);
		cout << setw(15) << y << setw(15) << s << setw(15) << sum << endl;

		
	}

	return 0;
}