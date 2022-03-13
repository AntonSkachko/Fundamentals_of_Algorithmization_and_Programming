#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int SPACE = 20;

void format_out(double x, double s, double y) {
    cout << setw(SPACE) << x << setw(SPACE) << s << setw(SPACE) << s << setw(SPACE) << abs(y - s) << '\n';
}

int main() {
    double a, b, h, x;
    int n;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "h = "; cin >> h;
    cout << "n = "; cin >> n;

    cout << setw(SPACE) << "x" << setw(SPACE) << "S(x)" << setw(SPACE) << "Y(x)" << setw(SPACE) << "|Y(x) - S(x)|" << '\n';
    x = a;
    while(x <= b) {
        double S = 0, Y = 0, mn = 1;

        int fact = 1;
        for(int i = 1; i <= n; i++) {
            mn *= 4 * x * x / (fact * (fact + 1));
            fact += 2;
            if(i % 2)  S -= mn;
                else    S += mn;

        }
        Y = 2 * (cos(x) * cos(x) - 1);
        format_out(x, S, Y);
        x += h;
    }
    system("pause");
    return 0;
}
