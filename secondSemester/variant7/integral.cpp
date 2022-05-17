#include <iostream>
using namespace std;

double function (double x);

int main() {

    double intervalBegin, intervalEnd;
    int count;
    double integral = 0, step;

    cout << "Enter begining of interval: ";
    cin >> intervalBegin;
    cout << "Enter end of interval: ";
    cin >> intervalEnd;
    cout << "Enter number of iterations: ";
    cin >> count;

    step = (intervalEnd - intervalBegin) / count;

    for (int i = 1; i <= count; ++i) {
        integral += step * function(intervalBegin + (i - 1) * step);
    }

    cout << "Integral is equal to: " << integral << endl;
    return 0;
}
double function(double x) {
    return x - 5 * sin(x) * sin(x);
}