#include <iostream>

using std::cin;
using std::cout;

double calculateRecurseBinaryPow(double x, int pow) {
  if(pow == 0) {
    return 1;
  }
  if((pow & 1) == 0) {
    double buf = calculateRecurseBinaryPow(x, pow >> 1);
    return buf * buf;
  } else {
    return x * calculateRecurseBinaryPow(x, pow - 1);
  }
}

double getRecurseBinaryPow(double x, int pow) {
  if(pow < 0) {
    return 1 / calculateRecurseBinaryPow(x, -1 * pow);
  } else {
    return calculateRecurseBinaryPow(x, pow);
  }
}

double getManuallyPow(double x, int pow) {
  if(pow < 0) {
    return 1 / getManuallyPow(x, -1 * pow);
  }
  if(pow == 0) {
    return 1;
  }
  double result = 1;
  while(pow != 0) {
    if((pow & 1) == 1) {
      result *= x;
    }
    x *= x;
    pow >>= 1;
  }
  return result;
}

int main() {
  double value;
  cout << "Enter x: ";
  cin >> value;
  int pow;
  cout << "Enter pow: ";
  cin >> pow;
  double recurse_pow = getRecurseBinaryPow(value, pow);
  double manually_pow = getManuallyPow(value, pow);
  cout << "Recurse pow = " << recurse_pow << "\n";
  cout << "Manually pow = " << manually_pow << "\n";
  return 0;
}
