#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
    double a;
    cout << "¬ведите а: ";
    cin >> a;
    while(a < 0) {
		cout << "ќшибка, а должно быть больше нул€\n¬ведите a: ";
		cin >> a;
    }
    double  b = sqrt((3 * a + 2) * (3 * a + 2) - 24 * a),
			c = 3 * sqrt(a) - 2 / sqrt(a);
	cout << "z1 = " << b / c << "\nz2 = " << -1 * sqrt(a) << '\n';
	system("pause");
    return 0;
}
