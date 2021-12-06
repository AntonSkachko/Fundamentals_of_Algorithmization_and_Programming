#include <iostream>
using namespace std;

int *createArray(int n) {
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	return array;
}

void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << endl;
	}
}

void deleteArray(int* array) {
	delete[] array;
}

void seachNumber(int* array_1, int n, int* array_2){
	int min = 100000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (array_1[i] == array_2[j]) {
				break;
			}
			else{
				if (min > array_1[i]) {
					min = array_1[i];
				}
			}
		}
	}
	cout << min;
}

int main() {
	int n;
	cout << "Enter n: "; cin >> n;
	cout << endl << "Enter element of the first array: ";
	int* array_1 = createArray(n);
	cout << endl << "Enter element of the second array: ";
	int* array_2 = createArray(n);

	cout << "Your first array: ";
	printArray(array_1, n);

	cout << "Your second array: ";
	printArray(array_2, n);

	cout << endl << "Your min number doesn't have in second array: ";
	seachNumber(array_1, n, array_2);
	return 0;
}