#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SPACE = 20;
double eps = 1e-7;

void precalc();

void format_out(double x, int cnt, double s, double y);

double get_Y(double x);

double get_S(double x, int& cnt);

int main() {
    double a, b, h, x;
    int cnt;
    cout << "a = ";     cin >> a;
    cout << "b = ";     cin >> b;
    cout << "h = ";     cin >> h;
    cout << "Eps = ";   cin >> eps;
    precalc();
    x = a;
    while (x <= b) {
        double S = get_S(x, cnt);
        format_out(x, cnt, S, get_Y(x));
        x += h;
    }
    system("pause");
    return 0;
}

void precalc() {
    cout << setw(SPACE) << "x" << setw(SPACE) << "Max k" << setw(SPACE) << "S(x)" << setw(SPACE) << "Y(x)"
         << setw(SPACE) << "|Y(x) - S(x)|" << '\n';
}

void format_out(double x, int cnt, double s, double y) {
    cout << setw(SPACE) << x << setw(SPACE) << cnt << setw(SPACE) << s << setw(SPACE) << y << setw(SPACE) << abs(y - s)
         << '\n';
}

double get_S(double x, int& cnt) {
    double S = 0, multiple = 1;
    cnt = 1;
    while (abs(multiple) >= eps) {
        multiple *= -4 * x * x / ((2 * cnt) * (2 * cnt - 1));
        cnt++;
        S += multiple;
    }
    cnt--;
    return S;
}

double get_Y(double x) {
    return 2 * cos(x) * cos(x) - 2;
}

/**
f(k) = -1^(k) * x^(2k + 1) / (2k + 1)!

f(k+1) = -1^(k + 1) * x^(2k + 3) / (2k + 3)!

(2k+3)! = (2k+1)! * (2k+2) * (2k+3)
x^(2k+3) = x^(2k+1) * x^2
1^(k+1) = -1^(k) * (-1)

f(k + 1) = f(k) * (x * x * (-1) / ((2k + 2) * (2k + 3)

A = f(k)

A *= (x * x * (-1) / ((2k + 2) * (2k + 3);

 */