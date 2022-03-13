#include <iostream>
using std::cin;
using std::cout;
using std::swap;

int* createArray(int& size) {
  cout << "Enter array size = ";
  cin >> size;
  while(size < 1) {
    cout << "Error. Enter valid array size (>0) = ";
    cin >> size;
  }
  int* arr = new int[size];
  cout << "Enter array: ";
  for (int index = 0; index < size; ++index) {
    cin >> arr[index];
  }
  return arr;
}

int findFirstZeroElement(int* arr, int size) {
  for (int index = 0; index < size; ++index) {
    if(arr[index] == 0) {
      return index;
    }
  }
  return INT_MIN;
}

int findLastZeroElement(int* arr, int size) {
  for (int index = size - 1; index >= 0; --index) {
    if(arr[index] == 0) {
      return index;
    }
  }
  return INT_MIN;
}

void reverseArrayBetween(int* array, int first_zero, int last_zero) {
  for (int index = first_zero + 1; 2 * index <= last_zero + first_zero; ++index) {
    swap(array[index], array[last_zero - index + first_zero]);
  }

}

void printArray(int* arr, int size) {
  for (int index = 0; index < size; ++index) {
    cout << arr[index] << ' ';
  }
  cout << '\n';
}

void deleteArray(int* arr) {
  delete[] arr;
}

int main() {
  int size;
  int* arr = createArray(size);
  int first_zero_index = findFirstZeroElement(arr, size);
  int last_zero_index = findLastZeroElement(arr, size);
  if(last_zero_index == INT_MIN) {
    cout << "Zero elements isn't found\n";
    return 1;
  }
  if(last_zero_index == first_zero_index) {
    cout << "Zero element is only one, but need 2\n";
    return 2;
  }
  cout << "Index of first zero element: " << first_zero_index << '\n';
  cout << "Index of last zero element: " << last_zero_index << '\n';
  cout << "Array: ";
  printArray(arr, size);
  reverseArrayBetween(arr, first_zero_index, last_zero_index);
  cout << "Result array: ";
  printArray(arr, size);
  deleteArray(arr);
  return 0;
}
