#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n: "; cin >> n;
	cout << "Enter m: "; cin >> m;

	int** matr = new int* [n];

	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
		}
	}

	int* temp;
	for (int i = 0; i + 1 < m; ++i) {
		for (int j = 0; j < m - i - 1; ++j) {
			if (matr[j][0] > matr[j + 1][0]) {
				temp = matr[j];
				matr[j] = matr[j + 1];
				matr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	for (int i = 0; i < n; i++) {
		delete[] matr[i];
	}
	delete[] matr;
	return 0;
}