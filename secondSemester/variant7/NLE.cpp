#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 0.0001;

double function(double x);

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b;
    cout << "¬ведите левую границу интервала а: "; cin >> a;
    cout << "¬ведите правую границу интервала b: "; cin >> b;
    double x0 = a, x1 = b;

    for (int it = 0; it < 1000000; it++) {
        x1 = function(x0);
        if (fabs(x1 - x0) < EPS) {
            cout << it << endl;
            break;
        }
        x0 = x1;
    }
    cout << x1 << endl;
}

double function(double x0) {
    return 5 * sin(x0) * sin(x0) + 5;
}