#include<iostream>

using namespace std;

string const ERROR_MESSAGE = "Error";

int main() {
	srand(time(0));
	int str; cout << "Enter number of strings="; cin >> str;
	int col; cout << "Enter number of columns="; cin >> col;
	cout << endl;
	int** mass = new int* [str];
	for (int i=0; i<str; i++) {
		mass[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cout << "Enter mass[" << i << "][" << j << "] = ";
			cin >> mass[i][j];
		}
		cout << endl;
	}
	for (int j = 0; j < str; j++) {
		int sum = 0;
		int stopStr=0;
		for (int &i = stopStr; i < col; i++) {
			sum += mass[i][j];
			if (mass[i][j] < 0) break;
		}
		if (stopStr != col) break;
		cout << "Sum of col N" << j << " is " << sum << endl;
	}

	system("Pause");
	return 0;
}