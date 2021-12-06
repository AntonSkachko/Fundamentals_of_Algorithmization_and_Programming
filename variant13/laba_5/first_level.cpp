#include <iostream>
using std::cin;
using std::cout;

double** createMatrix(int& row_count, int& col_count) {
  cout << "Enter row count = ";
  cin >> row_count;
  cout << "Enter col count = ";
  cin >> col_count;
  while (row_count < 1 || col_count < 1) {
    cout << "Error. Enter valid row and col count (>0)\n";
    cout << "Enter row count = ";
    cin >> row_count;
    cout << "Enter col count = ";
    cin >> col_count;
  }
  double** matrix = new double* [row_count];
  for (int row = 0; row < row_count; ++row) {
    matrix[row] = new double[col_count];
  }
  return matrix;
}

void enterMatrix(double** matrix, int row_count, int col_count) {
  for (int row = 0; row < row_count; ++row) {
    for (int col = 0; col < col_count; ++col) {
      cin >> matrix[row][col];
    }
  }
}

void deleteMatrix(double** matrix, int& row_count) {
  for (int row = 0; row < row_count; ++row) {
    delete[] matrix[row];
  }
  delete[] matrix;
  row_count = 0;
}

void printMatrix(double** matrix, int row_count, int col_count) {
  for (int row = 0; row < row_count; ++row) {
    for (int col = 0; col < col_count; ++col) {
      cout << matrix[row][col] << ' ';
    }
    cout << '\n';
  }
}

int findFirstColumnWithZero(double** matrix, int row_count, int col_count) {
  for (int col = 0; col < col_count; ++col) {
    for (int row = 0; row < row_count; ++row) {
      if (matrix[row][col] == 0) {
        return col;
      }
    }
  }
  return INT_MIN;
}

int main() {
  int row_count, col_count;
  double** matrix = createMatrix(row_count, col_count);
  enterMatrix(matrix, row_count, col_count);
  cout << "Matrix:\n";
  printMatrix(matrix, row_count, col_count);
  int first_column_with_zero =
      findFirstColumnWithZero(matrix, row_count, col_count);
  if(first_column_with_zero != INT_MIN) {
    cout << "Index of first column with zero = " << first_column_with_zero;
  } else {
    cout << "Matrix isn't have zero elements\n";
  }
  deleteMatrix(matrix, row_count);
  return 0;
}
