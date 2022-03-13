#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

const double PI = acos(-1);

int main()
{
	SetConsoleOutputCP(1251);
    double a;
    cout << "¬ведите а: ";
    cin >> a;
    double  z1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a),
			z2 = sqrt(8) * cos(a) * sin(PI / 4 + 2 * a);
	cout << "z1 = " << z1 << '\n';
	cout << "z2 = " << z2 << '\n';
	system("pause");
    return 0;
}
