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

bool isInArea(int& size, int& row, int& col) {
  return (col - row) * (size - 1 - row - col) < 0;
}

void findMultiplicationAndSum(double** matrix,
                              int size,
                              double& multiplication,
                              double& sum) {
  multiplication = 1;
  sum = 0;
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      if (isInArea(size, row, col)) {
        multiplication *= matrix[row][col];
        sum += matrix[row][col];
      }
    }
  }
}

int main() {
  int size;
  double** matrix = createSquareMatrix(size);
  cout << "Enter matrix:\n";
  enterSquareMatrix(matrix, size);
  cout << "Matrix:\n";
  printSquareMatrix(matrix, size);
  double multiplication, sum;
  findMultiplicationAndSum(matrix, size, multiplication, sum);
  cout << "Multiplication in this area: " << multiplication << '\n';
  cout << "Sum is this area: " << sum << '\n';
  deleteMatrix(matrix, size);
  return 0;
}
