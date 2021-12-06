#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double  x, z, d, c;

	cout << "введите z = "; cin >> z;
	cout << "введите d = "; cin >> d;
	cout << "введите c = "; cin >> c;

	cout << "если f = 2 * x введите 1" << endl;
	cout << "если f = x * x введите 2" << endl;
	cout << "если f = x / 3 введите 3" << endl;
	cout << "Выберете функцию " << endl;


	if (z < 0) {
		x = z * z - z;
		cout << "вы выбрали условие z < 0, и значение z * z - z" << endl;
	}
	else {
		x = pow(x, 3);
		cout << "вы выбрали условие z >= 0, и значение z * z * z" << endl;
	}
	switch (_getch()) 
	{
	case '1':		f = 2 * x;		break;
	case '2':		f = x * x;		break;
	case '3':		f = x / 3;		break;
	}

	cout << "   result = " << pow(sin(c * f + d * d + x * x), 3) << endl;
	return 0;
}