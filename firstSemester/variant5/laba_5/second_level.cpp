#include <iostream> 
#include <ctime>

using namespace  std;



int numOfElemts(int** mass, int i, int j) {
	int num = 0;
	for (int n = 0; n < i; n++) {
		for (int k = 1; k < j-1; k++) {
			if (mass[n][k] > mass[n][k+1] && mass[n][k] < mass[n][k-1]) num++;
		}
	}

	return num;
}

int main() {
	int n, m; cout << "Enter size of matrix" << endl;
	cout << "n="; cin >> n; 
	cout << "m="; cin >> m;
	
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "Enter mass[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
	int num = numOfElemts(a, n, m);
	cout <<"  kol os elem = "<< num << endl;

	system("Pause");
	return 0;
}