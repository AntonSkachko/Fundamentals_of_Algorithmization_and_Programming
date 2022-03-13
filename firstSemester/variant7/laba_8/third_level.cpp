#include <iostream>
using namespace std;

double getSqrt(const double& a, int n) {
    if (n == 0) {
        return 0.5 * (1 + a);
    }
    double buf = getSqrt(a, n - 1);
    return 0.5 * (buf + a / buf);
}

int main()
{
    double a, n;
    cout << "Enter a = ";   cin >> a;
    cout << "Enter n = ";   cin >> n;
    cout << getSqrt(a, n) << endl;
    return 0;
}