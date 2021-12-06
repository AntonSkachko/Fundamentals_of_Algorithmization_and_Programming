#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, answ;
    cout << "x = ";     cin >> x;
    cout << "y = ";     cin >> y;

    if (abs(x) + abs(y) <= 1 || x >= 0)        answ = max(x, y) + sqrt(x);
    else if (abs(x) + abs(y) > 0 || (x < 0 && y < 0)) answ = min(x, y) - sin(x) * sin(x) - cos(y) * cos(y);
        else answ = exp(x * x + abs(y));


    cout << "Result = " << answ << '\n';
    system("pause");
    return 0;
}
