#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int N, M, i, j;

    int sum_even_rows = 0, sum_odd_rows = 0, sum_even_cols = 0, sum_odd_cols = 0;

    cout << "Введите количество строк матрицы: ";    cin >> N;
    cout << "Введите количество столбцов матрицы: ";   cin >> M;
    int** mass = new int* [N]; 
    cout << endl;
    cout << "Заполните матрицу " << N << 'х' << M << endl;

    for (i = 0; i < N; i++)
    {
        mass[i] = new int[M]; 
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cout << "Введите число: ";
            cin >> mass[i][j];
        }
    }

    cout << "Полученная матрица: " << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i % 2 == 0)
                sum_even_rows += mass[i][j];
            else
                sum_odd_rows += mass[i][j];

            if (j % 2 == 0)
                sum_even_cols += mass[i][j];
            else
                sum_odd_cols += mass[i][j];

            cout << setw(6) << mass[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Сумма элементов в нечетных строках   :  " << sum_even_rows << endl;

    cout << "Сумма элементов в четных столбцах:  " << sum_odd_cols << endl;

    return 0;

}