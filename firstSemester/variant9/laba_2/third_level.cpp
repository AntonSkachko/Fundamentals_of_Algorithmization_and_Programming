#include <iostream>
#include <cmath>

using namespace std;

int main1()
{

	double x, y, m, z;
	cout << "Enter x: ";	cin >> x;
	cout << "Enter y: ";	cin >> y;
	cout << "Enter z: ";	cin >> z;

	m = max(y, z) / min(min(x, y), min(y, z));

	cout << "Result = " << m << endl;

	system("pause");
	return 0;
}