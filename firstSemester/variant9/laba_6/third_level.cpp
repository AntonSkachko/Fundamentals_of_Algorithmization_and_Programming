#include<iostream>
#include<string.h>
#include<cstdlib>
#include <string>

using namespace std;

int main1() {
	
	setlocale(LC_ALL, "rus");

	string str;	
	cout << "¬ведите элементы строки (не более 15):\n";
	getline(cin, str);

	for (int i = 0; i < 15; i++) {
		if (str[i] == ' ') {
			str[i] = '$';
		}
	}

	cout << "\n–езультат: " << str << endl;

	return 0;
}