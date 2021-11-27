#include <iostream>
#include <string>
using namespace std;

int main() {
	string l;
	cout << "Enter string: "; cin >> l;
	cout << "length of string: " << l.size() << endl;
	
	if (l.size() % 2 != 0) {
		l.erase(l.size() / 2, 1); // deleting of selectet element. count of deleted elements
	}
	cout << "String with deleted elemen: " << l << endl;
	return 0;

}