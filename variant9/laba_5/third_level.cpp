#include<iostream>
#include<cmath>

using namespace std;

int main1() {

    setlocale(LC_ALL, "rus");
    int n, i, j;
    double sum = 0.0;
    cout << "n = ";     cin >> n;
    double** a = new double* [n]; 
    for (i = 0; i < n; ++i)
        a[i] = new double[n];

    cout << "¬ведите элементы матрицы:" << endl;
    for (i = 0; i < n; ++i) 
    
        for (j = 0; j < n; ++j) 
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    
    for (i = 1; i < n; ++i) 
        for (j = 0; j < i; ++j) 
            sum += fabs(a[i][j]);

    delete[] a;

    cout << "—умма ниже главной диагонали = " << sum << endl;

    return 0;
}