#include <iostream>

using namespace std;
int main() {

	cout << "Whrite size of matrix" << endl;

	int n,m,i,j,count = 0, sum = 0;    
	cout << "Number of rows = ";     cin >> n;
	cout << "Number of columns = ";  cin >> m;
	
	int** a = new int* [n];

	for ( i = 0; i < n; i++) 
	{
		a[i] = new int[m];
		for (j = 0; j < m; j++) 
		{
			cout << "array[" << i << "][" << j << "] = "; cin >> a[i][j];
		}
	}

	cout << "\nMatrix:\n\n";
	for ( i = 0; i < n; i++) 
	{
		for ( j = 0; j < m; j++)
			cout<< a[i][j]<< "  ";
		cout << endl;
	}
	for ( i = 0; i < n; i++)	
		for ( j = 0; j < m; j++)
		{
			for (int t = 0; t < n; t++) sum += a[t][j];
			sum -= a[i][j];
			if (sum < a[i][j]) count++;
			sum = 0;
		}	
	cout << "The result = " << count << endl;
	for ( i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	system("pause");
	return 0;
}