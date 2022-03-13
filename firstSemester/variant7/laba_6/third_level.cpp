#include <iostream>
#include <string>
using namespace std;

string replaceSymbol(string& s1) {
	for (int i = 0; i < s1.size(); ++i) {
		if (i % 3 == 0 && i % 4 != 0) {
			s1[i] = '%';
		}
		if (i % 4 == 0 && i % 3 != 0) {
			s1[i] = '&';
		}
		if (i % 12 == 0 && i != 0) {
			s1[i] = '#';
		}
		
	}
	return s1;
}

int main() {
	string s1;
	cout << "Enter string: "; cin >> s1;
	cout << "Result string:" << replaceSymbol(s1);
	return 0;
}