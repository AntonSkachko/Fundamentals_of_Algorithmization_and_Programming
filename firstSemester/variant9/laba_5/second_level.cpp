#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;

	cout << "Введите количество строк:"; cin >> m;
	cout << "Введите количество столбцов:"; cin >> n;
	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	int io = 0, h;
	for (int f = 0; f < n; f++)
	{
		io = f;
		int max1 = a[f][0], max;
		for (int s = 0; s < m; s++)
			if (a[f][s] > max1)
			{
				max1 = a[f][s];
			}

		for (int i = f; i < n; i++) {
			int max = a[f][0];

			for (int y = 0; y < m; y++)
			{
				if (a[i][y] > max)
				{
					max = a[i][y];
				}
			}

			if (max < max1)
			{
				max1 = max;
				io = i;

			}

		}
		swap(a[f], a[io]);
	}
	cout << "\nНовый массив:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}

	return 0;
}