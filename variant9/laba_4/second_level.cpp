#include<iostream>

using namespace std;

int main2() {

	setlocale(LC_ALL, "rus");

	int n;
	cout << "¬ведите n: "; cin >> n;

	int* a = new int[n], sum = 0.0;

	cout << "¬ведите " << n << " элементов массива: " << endl;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int min = a[0];
	int ind = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			ind = i;
		}
	}


	for (int i = n; i >= ind; i--) {
		if (a[i] < 0)
		{
			if (i != ind) {
				for (int j = ind; j <= i; j++)
					sum += abs(a[j]);
			}
			break;
		}
	}

	cout << "–езультат равен " << sum << endl;

	delete[]a;

	return 0;
}