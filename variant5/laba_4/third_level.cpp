#include <iostream>
#include <ctime>

using namespace std;

int *createArr(int n) {
	int* mass = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter mass[" << i << "] = ";
		cin >> mass[i];
	}
	return mass;
}

int *deleteExc(int *mass, int n, int&k) {
	k = 0;
	for (int i = 0; i < n - k; i++) {
		for (int c = i + 1; c < n-k; c++) {
			while (mass[i] == mass[c]) {
				for (int f = c; f < n-k; f++) {
					mass[f] = mass[f + 1];
				}
				k++;
			}
		}
	}

	return mass;
}

void outArr(int* mass, int n ) {
	for (int i = 0; i < n; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int main() {
	srand(time(0));
	int n;
	cout << "n="; cin >> n;
	
	int *arr = createArr(n);
	outArr(arr, n);
	int numExc;
	deleteExc(arr, n, numExc);
	outArr(arr, n-numExc);
	delete[]arr;

	system("pause");
	return 0;
}















