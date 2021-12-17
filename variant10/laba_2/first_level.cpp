#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, y, z, m;
	cout << "x = "; cin >> x ;
	cout << "y = "; cin >> y ;
	cout << "z = "; cin >> z ; 
	m = max(max(x, y), max(y, z)) / min((x, y), z);
	cout << "   result = " << m << endl;
	return 0;

}

