#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int SPACE = 20;
const double PI = acos(-1);
double eps = 1e-5;

void selectMenu();

int main() {
    selectMenu();
    return 0;
}

double getS(double x) {
    double s = 0, 
           multiple = 1;
    int k = 1;
    while (abs(multiple / k) >= eps) {
        multiple *= x;
        s += multiple * cos(k * PI / 3) / k;
        k++;
    }
    return s;
}

double getY(double x) {
    return -0.5 * log(1 - 2 * x * cos(PI / 3) + x * x);
}

double getAbs(double x) {
    return abs(getY(x) - getS(x));
}

void outRez(double x_start, double x_end, double x_step, double func(double)) {
    double x = x_start;
    cout << setw(SPACE) << "x" << setw(SPACE) << "F(X)" << '\n';
    while (x <= x_end) {
        cout << setw(SPACE) << x << setw(SPACE) << func(x) << '\n';
        x += x_step;
    }
}

void getStartValues(double& x_start, double& x_end, double& x_step) {
    cout << "Enter a, b, h: ";
    cin >> x_start >> x_end >> x_step;
}

void selectMenu() {
    int choose;
    double x_start, x_end, x_step;
    while (true) {
        cout << "Enter 0 to exit" << endl;
        cout << "Enter 1 to calculate F(X) = Y(x)" << endl;
        cout << "Enter 2 to calculate F(X) = S(x)" << endl;
        cout << "Enter 3 to calculate F(X) = |Y(X) - S(X)|" << endl;
        cin >> choose;
        if (choose == 0) {
            cout << "Menu close\n";
            break;
        } else if (choose == 1) {
            getStartValues(x_start, x_end, x_step);
            outRez(x_start, x_end, x_step, getY);
        } else if (choose == 2) {
            getStartValues(x_start, x_end, x_step);
            outRez(x_start, x_end, x_step, getS);
        } else if (choose == 3) {
            getStartValues(x_start, x_end, x_step);
            outRez(x_start, x_end, x_step, getAbs);
        } else {
            cout << "Input error\n";
        }
    }
}