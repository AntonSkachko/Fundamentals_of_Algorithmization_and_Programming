#include <iostream>
using namespace std;

int** createMatrix(int line, int column);
void createVector(int line, int** matrix, int column);

int main() {
	int line, column;
	cout << "Enter line: "; cin >> line;
	cout << "Enter column: "; cin >> column;
	
	int** matrix = createMatrix(line, column);

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	createVector(line, matrix, column);
	
	for (int i = 0; i < line; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;

	return 0;
}

int** createMatrix(int line, int column) {
	int** matr = new int* [line];

	for (int i = 0; i < line; i++) {
		matr[i] = new int[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << "matr[" << i << "][" << j << "]: ";
			cin >> matr[i][j];
		}
	}
	return matr;
}

void createVector(int line, int**matrix, int column) {
	int* myVector = new int[column];
	for (int i = 0; i < line; i++) {
		int buff = 1;
		for (int j = 1; j < column; j++) {
			if (matrix[i][j] > matrix[i][j - 1]) {
				buff++;
			}
		}
		if (buff  == column) {
			myVector[i] = 1;
		}
		else {
			myVector[i] = 0;
		}
	}
	
	for (int i = 0; i < column; i++) {
		cout << myVector[i] << " ";
	}
}
