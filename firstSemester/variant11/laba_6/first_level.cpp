#include <iostream>
#include <string>

using namespace std;


bool is_string(char s) {
	return (s >= '0' && s <= '9');
}


bool is_multiple_of_three(int n) {
	return (n % 3 != 0);
}


int main() {
	string s;
	cout << "Enter the string: ";
	cin >> s;
	int L = s.length();

	cout << "String length(L) is " << L << endl;
	if (L % 3 == 0)
	{
		for (int i = 0; i < L; i++)
		{
			if (is_string(s[i]))
			{
				if (is_multiple_of_three(s[i] - '0')) {
					cout << s[i] << " ";
				}
			}
			else
			{
				cout << s[i] << " ";
			}
		}
	}
}
