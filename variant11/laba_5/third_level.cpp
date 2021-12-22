#include <iostream>

using namespace std;


bool algorithm(double x, double y) {
    return (x > y);
}


int main() {
    int n;
    double **a;
    cout << "Input N: ";
    cin >> n;
    int ** b;
    
    // Create matrix N x N of Int
    b = new int* [n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
    }

    // Create matrix N x N of Double
    a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    } // end
    
    cout << "--------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (algorithm(a[i][j], a[j][j])) {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }

            cout << b[i][j] << " ";            
        }
        cout << endl;
    }
}
