#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void viewArray(int* array, int size);
void linearSearch(int* array, int requiredKey, int size);
void directSelectionSort(int* array, int size);
void QuickSort(int* array, int left, int right);
int binarySearch(int* array, int left, int right, int key);

int  main() {
	srand(time(NULL));
	
	int size;
	cout << "Enter size array: "; cin >> size;
	int* array = new int[size];
	
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 60;
	}

	int choice, key;
	while (true) {
		cout << "\n1 - exit\n2 - linear search \n3 - direct selection sort\n"
			<< "4 - sorting by QuickSort\n5 - binary search \n6 - show array\n Enter number: ";
		cin >> choice;

		switch (choice) {
			case 1: 
				delete[] array;
				return 0;
			case 2:
				cout << "What number needs to find?: "; cin >> key;
				linearSearch(array, key, size);
				break;
			case 3: 
				directSelectionSort(array, size);
				cout << "\n Your sorted array ";
				viewArray(array, size);
				break;
			
			case 4: 
				QuickSort(array, 0, size - 1);
				cout << "\n Your sorted array ";
				viewArray(array, size);
				break; 

			case 5:
				cout << "What number needs to fidn?: "; cin >> key;
				QuickSort(array, 0, size - 1);
				cout << binarySearch(array, 0, size - 1, key);

				break;

			case 6:
				cout << "Your array ";
				viewArray(array, size);
				break;
		}
		
	}
	return 0;
}

void viewArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

void linearSearch(int* array, int key, int size) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (array[i] == key) {
			index = i;
			cout << "index of your number is " << index;
		}
	}
	if (index == -1) {
		cout << "this number isn't on your array!!";
	}
}

void QuickSort(int* array, int left, int right) {
	if (left >= right) {
		return;
	}

	int wall = left, pivot = right;
	for (int i = left; i < right; i++) {
		if (array[i] < array[pivot]) {
			int temp = array[i];
			array[i] = array[wall];
			array[wall] = temp;
			wall++;
		}
	}

	int temp = array[wall];
	array[wall] = array[pivot];
	array[pivot] = temp;
	QuickSort(array, left, wall - 1);
	QuickSort(array, wall + 1, right);
}


void directSelectionSort(int* array, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int binarySearch(int* array, int left, int right, int key) {
	int midd = 0;
	while (1) {
		midd = (left + right) / 2;
		if (key < array[midd]) {
			right = midd - 1;
		}
		else if (key > array[midd]) {
			left = midd + 1;
		}
		else {
			return midd;
		}
		if (left > right) {
			return -1;
		}
	}

}