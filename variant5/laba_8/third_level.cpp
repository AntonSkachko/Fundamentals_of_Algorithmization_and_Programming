#include<iostream>
#include<string>

using namespace std;

string const ERROR_MESSAGE = "Error";

void findStrLengthByRec(string str, int& strLength);
void findStrLengthByFunc(string str, int& strLength);

int main() {
	string str;
	cout << "Enter string" << endl;
	getline(cin, str);
	int strLength = 0;
	int chooseType;
	cout << "Choose how to find length:" << endl << "1) by recursia;" << endl << "2) by function;" << endl;
	cin >> chooseType;
	switch (chooseType) {
	case 1: {
		findStrLengthByRec(str, strLength);
		break;
	}
	case 2: {
		findStrLengthByFunc(str, strLength);
		break;
	}
	default: {
		cout << ERROR_MESSAGE << endl;
		break;
	}
	}
	cout << "String length=" << strLength << endl;

	system("Pause");
	return 0;
}

void findStrLengthByRec(string str, int &strLength) {
	strLength++;
	if (str[strLength] != '\0') findStrLengthByRec(str, strLength);
}

void findStrLengthByFunc(string str, int& strLength) {
	while (str[strLength] != '\0') strLength++;
}