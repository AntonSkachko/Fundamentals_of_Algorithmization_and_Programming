#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n: "; cin >> n;
	std::cout << "Enter m: "; cin >> m;

	int** matr = new int* [n];

	bool* have_negative = new bool[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		have_negative[i] = false;
	}

	bool sum_exist = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
		}
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			if (matr[row][col] < 0) {
				have_negative[row] = true;
				sum_exist = true;
				break;
			}
		}
	}
	if (!sum_exist) {
		cout << "There no are rows with negative elements" << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (have_negative[i]) {
				for (int j = 0; j < n; j++) {
					sum += matr[i][j];
				}
			}
		}
		cout << "Sum = " << sum << endl;
	}
	for (int row = 0; row < n; row++) {
		delete[] matr[row];
	}

	delete[] matr;
	delete[] have_negative;
	return 0;
}