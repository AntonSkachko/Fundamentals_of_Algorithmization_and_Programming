#include <iostream>
#include <string>
using namespace std;

int main() 
{
	bool flag = true;
	string text; 
	char a;
	cout << "Write content of line: "; getline(cin, text);
	cout << "Enter symbol : ";    cin >> a;
	for (int i = 0; i < text.size(); i++) 
		if (text[i] == a) 
		{
			text = text.substr(0, i + 1) + a + text.substr(i + 1, text.size() - i - 1);
			i++;
			flag = false;
		}
	if (!flag) cout << text << endl;
	else cout << "There is no symbol " << a;
	return 0;
}