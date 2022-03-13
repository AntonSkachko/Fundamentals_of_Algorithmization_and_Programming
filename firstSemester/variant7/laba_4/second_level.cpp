#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main() {
	srand(time(0));
	int n, choice, index_x = -1, index_y = -1, sum = 0;
	cout << "n: "; cin >> n;
	int* arr = new int[n];

	cout << "How do you want to work your programm" << endl;
	cout << "Random: Enter 1" << endl;
	cout << "Enter in keyboard: Enter 2" << endl;

	cin >> choice;

	switch (choice) {
		case 1:
			for (int i = 0; i < n; i++) {
				arr[i] = 1 + rand() % 10;
			}
			break;
		case 2:
			for (int i = 0; i < n; i++){
				cout << "Enter " << i << " elemet: ";
				cin >> arr[i];
			}

	}
	
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			index_x = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			index_y = i;
			break;
		}
	}

	for (int i = index_x; i < index_y; i++) {
		sum += arr[i];
	}

	cout << sum;

	delete[]arr;
	return 0;
}
