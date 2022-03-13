#include <iostream>
using namespace std;

void shift(int x, int* a, int k) {
	int* t = new int[x];

	for (int i = 0; i < x; i++) {
		t[(i + k) % x] = a[i];
	}

	for (int i = 0; i < x; i++) {
		a[i] = t[i];
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	int x, k;
	cout << "¬ведите x: "; cin >> x;
	cout << "¬ведите k: "; cin >> k;

	int* a = new int[x];

	for (int i = 0; i < x; i++) {
		cin >> a[i];
	}

	shift(x, a, k);
	for (int i = 0; i < x; i++) {
		cout << a[i] << " ";
	}

	delete[] a;

	return 0;
}