#include <iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int** createMatrix(int& s, int& l) {
	cout << "Enter line count: ";
	cin >> s;
	cout << "Enter column count: ";
	cin >> l;
	int** m = new int* [s];
	for (int i = 0; i < s; i++)
	{
		m[i] = new int[l];
	}
	return m;
}

void setMatrix(int** m, int s, int l) {
	cout << "Enter elements of matrix: ";
	
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cin >> m[i][j];
		}
	}
}

void printMatrix(int** m, int s, int l) {
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteMatrix(int** m, int& s) {
	for (int i = 0; i < s; i++)
	{
		delete[] m[i];
	}
	delete[] m;
	s = 0;
}

void task1() {
	cout << "Task1" << endl << endl;
	int s, l;
	int** m = createMatrix(s, l);
	setMatrix(m, s, l);
	printMatrix(m, s, l);
	int sum = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (j>i)
			{
				sum += m[i][j];
			}
		}
	}
	cout <<"sum = " << sum << endl;
	deleteMatrix(m, s);
}

void task2() {
	cout << "Task2" << endl << endl;
	int s, l;
	int** m = createMatrix(s, l);
	setMatrix(m, s, l);
	printMatrix(m, s, l);
	bool sim = true;
	for (int i = 0;  i<s; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (m[i][j] != m[l - 1 - j][s - 1 - i])
			{
				sim = false;
				break;
			}
		}
		if (!sim)
		{
			break;
		}
	}
	cout << ((sim) ? "matrix is simmetric" :
		"matrix isn't simmetric") << endl;
	deleteMatrix(m, s);
}

void task3() {
	cout << "Task3\n";
	int n;
	int** m = createMatrix(n, n);
	int sum=0;
	setMatrix(m, n, n);
	printMatrix(m, n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m[i][0]<0)
			{
				sum += m[i][j];
			}
		}
	}
	cout <<"sum = " << sum;
	deleteMatrix(m, n);
}

int main() {
    task1();
	return 0;
}