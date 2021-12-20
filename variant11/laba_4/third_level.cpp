#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "Enter n:";
	cin >> number;

 	if (number == 0) {
		cout << "Your number is 0";
		return 0;
	}

	int index = 0, num = number;
	while (number > 0) {
		index++;
		number /= 10;
	}
	int* array = new int[index];

	for (int i = 0; i < index; i++) {
		array[i] = pow(num % 10, 2);
		num /= 10;
	}

	cout << "Result: ";
	for (int i = index - 1; i > -1; i--) {
		cout  << array[i] << " ";
	}

	return 0;

}