#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cout << "Enter string: "; cin >> s1;
	for (auto c : s1) {
		if (c >= '0' && c <= '9') {
			s2 += c;
		}
		if(c == '.' && s2[s2.size()- 1] >= '0'
			&& s2[s2.size() - 1] <= '9') {
			s2 += c;
		}
		if (c == 'e' && s2[s2.size() - 1] >= '0'
			&& s2[s2.size() - 1] <= '9') {
			s2 += c;
		}
		if (c == '-' && s2[s2.size() - 1] >= 'e') {
			s2 += "-";
		}
		if (c == '+' && s2[s2.size() - 1] >= 'e') {
			s2 += '+';;
		}
	}
	cout << "Real floating point number: " << s2;
	return 0;
}