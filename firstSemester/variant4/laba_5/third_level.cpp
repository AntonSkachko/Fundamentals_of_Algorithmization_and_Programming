#include<iostream>
using namespace std;
int main()
{
	int size,i,j;
	cout << "Enter size of matrix : "; cin >> size;
	int** a = new int* [size];
	for ( i = 0; i < size; i++)
	{
		a[i] = new int[size];
		for ( j = 0; j < size; j++) {
			cout << "Matrix [" << i << "] [" << j << "] = "; cin >> a[i][j];
		}
	}
	cout << "Matrix :\n";
	for ( i = 0; i < size; i++)
	{
		for ( j = 0; j < size; j++) cout << " " << a[i][j];

		cout << endl;
	}
	cout << endl;
	cout << "New matrix :\n";
	for ( i = 0; i < size; i++) {
		for ( j = 0; j < size; j++) 	cout << " " << a[size - j - 1][i];
		cout << endl;
	}

	for ( i = 0; i < size; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}