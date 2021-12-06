#include <iostream>
using namespace std;

int main() {
	int n, average = 0;
	cout << "n: ";  cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			average += arr[i];
		}
	}
	cout << "average: " << average << endl;


	int k, max_ = 0, index_max = 0, multiplication = 1;
	cout << "k: "; cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		if (arr[i] > max_) {
			max_ = arr[i];
			index_max = i;
		}
	}

	for (int i = index_max; i < k; i++) {
		multiplication *= arr[i];
	}
	cout <<"multiplication: " << multiplication;

	delete[]arr;
	return 0;
}