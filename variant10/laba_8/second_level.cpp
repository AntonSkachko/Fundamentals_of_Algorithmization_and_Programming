#include <iostream>
using namespace std;

double sqrtPlus(int n, int a = 1) {
    if (a == n) {
        return sqrt(n);
    }
    return sqrt(a + sqrtPlus(n, a + 1));
}
int main()
{
    double n;
    cout << "n = ";   cin >> n;
    cout << sqrtPlus(n);
    return 0;
}