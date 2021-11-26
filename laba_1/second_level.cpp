#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b; // variables
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;

	double x, y; // additional variables
	
	x = (a - 1) * sqrt(a) - (b - 1) * sqrt(b);
	y = sqrt(a * a * a * b) + a * b + a * a - a;

	cout << "First result: " << x / y << endl;
	cout << "Second result: " << (sqrt(a) - sqrt(b)) / a;
	return 0;
}