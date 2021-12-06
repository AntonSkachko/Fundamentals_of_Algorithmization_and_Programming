#include <iostream>
using std::cin;
using std::cout;

double** createSquareMatrix(int& size) {
  cout << "Enter square matrix size = ";
  cin >> size;
  while (size < 2) {
    cout << "Error. Enter valid square matrix size (>1)\n";
    cout << "Enter square matrix size = ";
    cin >> size;
  }
  double** matrix = new double* [size];
  for (int row = 0; row < size; ++row) {
    matrix[row] = new double[size];
  }
  return matrix;
}

void enterSquareMatrix(double** matrix, int size) {
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      cin >> matrix[row][col];
    }
  }
}

void deleteMatrix(double** matrix, int& size) {
  for (int row = 0; row < size; ++row) {
    delete[] matrix[row];
  }
  delete[] matrix;
  size = 0;
}

void printSquareMatrix(double** matrix, int size) {
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      cout << matrix[row][col] << ' ';
    }
    cout << '\n';
  }
}

double findMinElementBehindSideDiagonal(double** matrix, int size) {
  double min = matrix[size - 1][size - 1];
  for (int row = size - 1; row >= 0; --row) {
    for (int col = size - row; col < size; ++col) {
      if(min > matrix[row][col]) {
        min = matrix[row][col];
      }
    }
  }
  return min;
}

int main() {
  int size;
  double** matrix = createSquareMatrix(size);
  cout << "Enter matrix:\n";
  enterSquareMatrix(matrix, size);
  cout << "Matrix:\n";
  printSquareMatrix(matrix, size);
  double min = findMinElementBehindSideDiagonal(matrix, size);
  cout << "Min element behind side diagonal = " << min << '\n';
  deleteMatrix(matrix, size);
  return 0;
}
