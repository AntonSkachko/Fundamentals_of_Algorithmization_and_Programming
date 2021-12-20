#include<iostream> 
#include<string>

using namespace std;

string const ERROR_MESSAGE = "Error";

int main() {
	string str;
	cout << "Enter string" << endl;
	getline(cin, str);
	int size = str.length();
	for (int i = 0; i < size; i++) {
		if (str[i] != 48 && str[i] != 49) {
			cout << ERROR_MESSAGE << endl;
			exit(0);
		}
	}
	int group = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] == 49) {
			group++;
			int numbOfOne = 1;
			i++;
			for (i; i < size; i++) {
				if (str[i] == 48) {
					cout << "In group N" << group << " numb of 1=" << numbOfOne << endl;
					break;
				}
				numbOfOne++;
				if (i == size - 1) {
					cout << "In group N" << group << " numb of 1=" << numbOfOne << endl;
					exit(0);
				}
			}
		}
	}
	
	system("Pause");
	return 0;
}