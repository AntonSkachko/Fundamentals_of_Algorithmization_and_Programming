#include <iostream>
using namespace std;

double getSqrt(const double& a, int n) {
	if (n == 0) {
		return 0.5 * (1 + a);
	}
	double buf = getSqrt(a, n - 1);
	return 0.5 * (buf + a / buf);
}

int main() {
	double a, n;
	cout << "Enter a = "; cin >> a;
	cout << "Enter n = "; cin >> n;
	cout << "Using recursion: " << getSqrt(a, n) << endl;

	double buf1, buf = 0.5 * (1 + a);

	while (n != 0) {
		buf1 = buf;
		buf = 0.5 * (buf1 + a / buf1);
		n--;
	}
	cout <<"Using the recursive formula: " << buf << endl;
	return 0;
}