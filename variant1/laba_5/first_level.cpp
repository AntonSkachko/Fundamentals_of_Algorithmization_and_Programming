#include <iostream>
using namespace std;

int main() {
	int line, column;
	cout << "Enter line: "; cin >> line;
	cout << "Enter column: "; cin >> column;

	int** matr = new int* [line];
	for (int i = 0; i < line; i++) {
		matr[i] = new int[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << "Matr[" << i << "][" << j << "]: "; 
			cin >> matr[i][j];
		}
	}

	int* yourArray = new int[column];

	for (int i = 0; i < column; i++) {
		yourArray[i] = 0;
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			if (matr[i][j] == 0) {
				yourArray[j]++;
			}
		}
	}
	int xyq = 0;
	for (int i = 0; i < column; i++) {
		if (yourArray[i] != 0) {
			xyq++;
		}
	}
	cout << xyq;
	delete yourArray;
	for (int i = 0; i < line; i++) {
		delete[] matr[column];
	}
	delete[] matr;
	return 0;
}