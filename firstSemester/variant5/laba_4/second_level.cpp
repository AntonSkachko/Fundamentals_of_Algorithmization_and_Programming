#include <iostream>

using namespace std;

int main()
{
	int n,num = 0;
	cout << "Number of elements="; cin >> n;
	double* mass = new double[n];
	double sum=0;
	for (int i = 0; i < n; i++) {
		cout << "Enter mass[" << i << "]="; cin >> mass[i];
		if (mass[i] < 0) 
		{
			sum += mass[i];
			num++;
		}
	}
	if (num == 0) cout << "No negative" << endl;
	else
	{
		sum /= num;
		cout << "Average=" << sum << endl;
	}

	system("pause");
	return 0;
}