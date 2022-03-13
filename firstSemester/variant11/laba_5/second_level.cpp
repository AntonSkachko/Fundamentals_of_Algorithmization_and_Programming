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
			cout << "matr[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	}

	int count = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (matr[i][j] < matr[i + 1][j] && matr[i][j] > matr[i - 1][j]) {
				if (i != 0 && i != n){
					count++;
				}
			}
		}
	}

	cout << "Resutl: " << count;
	return 0; 
}