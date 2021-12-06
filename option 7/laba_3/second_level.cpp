#include <iostream>
#include <cmath>
using namespace std;
double PI = acos(-1);

int main() {
	double a, b, h, n, x, y, s;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "h = "; cin >> h;
	cout << "n = "; cin >> n;
	int k;
	s = 0;
	for (x = a; x <= b; x += h) {
		s = 0;
		for (k = 1; k <= n; k++) {
			s += pow(x, k) * cos(k * PI / 3) / k;
		}
		y = -0.5 * log(1 - 2 * x * cos(PI / 3) + x * x);
		cout << "x = " << x << "\t\t";
		cout << "s = " << s << "\t" << "y = " << y << "\t";
		cout << "|y - s| = " << abs(y - s) << endl;
	}
	system("pause");
	return 0;
}