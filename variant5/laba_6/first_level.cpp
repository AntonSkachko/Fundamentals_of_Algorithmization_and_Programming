#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cout << "Enter your string"<<endl;
	getline(cin,str);
	int stringSize = str.length();
	for (int i = 0; i < stringSize; i++) {
		string newStr;
		while (str[i] >= 48 && str[i] <= 58) {
			newStr += str[i];
			i++;
			if (i == stringSize - 1) {
				cout << newStr << " ";
				exit(0);
			}
		}
		cout << newStr<<" ";
	}
	cout << endl;


	system("Pause");
	return 0;
}