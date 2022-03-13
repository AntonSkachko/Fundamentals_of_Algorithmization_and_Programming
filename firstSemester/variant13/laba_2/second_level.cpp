#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, a, k, m, z, phi, n;
    cout << "k = "; cin >> k;
    cout << "m = "; cin >> m;
    cout << "z = "; cin >> z;
    cout << "n = "; cin >> n;

    if(z > 1) x = z;
    else  x = z * z + 1;

    cout << "Write 1 for phi(x) = 2 * x\n";
    cout << "Write 2 for phi(x) = x * x\n";
    cout << "Write 3 for phi(x) = x / 3\n";
    int type;
    cin >> type;
    switch(type) {
        case 1: phi = 2 * x; cout << "phi(x) = 2 * x" << endl; break;
        case 2: phi = x * x; cout << "phi(x) = x * x" << endl; break;
        case 3: phi = x / 3; cout << "phi(x) = x / 3" << endl; break;
        default: cout << "Error\n"; return 1;
    }

    cout << "   Result = " << sin(n * phi) + cos(k * x) + log(m * x) << '\n';
    system("pause");
    return 0;
}
