#include <iostream>
using namespace std;

int max1(int x, int y, int z) {
	if (x > y  && x > z) {
		return x;
	}
	else if (y > x && y > z) {
		return y;
	}
	else {
		return z;
	}
}

int min1(int x, int y) {
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}

int main() {
	int x, y, z, m;
	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "Enter z: "; cin >> z;
	
	if (min1(x, y) == 0) {
		cout << "Error";
		return 0;
	}
	m = max1(x, y, z) / min1(x, y) + 5;
	cout << "Result: " << m;

	return 0;
}