#include <iostream>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n: "; cin >> n;
	cout << "Enter m: "; cin >> m;
	int** matr = new int*[n];

	for (int i = 0; i < n; i++) {
		matr[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}

	int k;
	cout << "Enter k: "; cin >> k;

	int count = 0, sum = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			sum += matr[i][j
			];
		}
		if (sum < k) {
			count++;
		}
	}

	cout << "Result: " << count;
}