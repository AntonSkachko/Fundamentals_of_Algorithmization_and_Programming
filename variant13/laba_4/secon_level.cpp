#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    int type = -1;
    do {
        cout << "Enter 0 if you want fill array with random values\n";
        cout << "Enter 1 if you want fill array using the keyboard\n";
        cin >> type;
    } while(type != 0 && type != 1);
    int n;
    cout << "n = ";
    cin >> n;
    int *a = new int[n];
    int max_, mod;
    if(type == 1) {
        cout << "Enter the array (" << n << " elements)\n";
        for(int i = 0; i < n; i++)
            cin >> a[i];
    } else {
        cout << "Enter the maximum allowed value\n";
        cout << "max = ";
        cin >> mod;
        cout << "Enter 0 if you don't need negative elements\n";
        cout << "Enter 1 if you need negative elements\n";
        cin >> type;
        if(type == 0) {
            max_ = 0;
        } else {
            max_ = mod;
            mod = mod * 2 + 1;
        }
        for(int i = 0; i < n; i++) {
            a[i] = rand() % mod - max_;
        }
        cout << "Array:\n";
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    int zero_ind = -1;
    for(int i = n - 1; i >= 0; --i) {
        if(a[i] == 0) {
            zero_ind = i;
            break;
        }
    }
    if(zero_ind == -1) {
        cout << "Don't have zero element\n";
        return 1;
    }
    if(zero_ind == n - 1) {
        cout << "Zero element is last\n";
        return 2;
    }
    int array_sum = 0;
    for(int i = 0; i < n; i++) {
        array_sum += a[i];
    }
    cout << "All right\n";
    double arithmetic_mean = 1. * array_sum / n;
    cout << "Arithmetic_mean = " << arithmetic_mean << '\n';
    long long multiplication = 1;
    for(int i = zero_ind + 1; i < n; i++) {
        if(a[i] <= arithmetic_mean)
            multiplication *= a[i];
    }
    cout << "Multiplication = " << multiplication << '\n';
    system("pause");
    return 0;
}
