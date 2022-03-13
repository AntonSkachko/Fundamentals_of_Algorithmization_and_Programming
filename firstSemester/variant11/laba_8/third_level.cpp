#include <iostream>
using namespace std;

double rec(int n) {
  if(n <= 1) {
    return 1 / 1.5;
  }
  return 1 / (n + rec(n - 1));
}

int main() {
  int n;
  cout << "Enter n = ";
  cin >> n;
  cout << "F(x) = " << rec(n) << endl;
  return 0;
}
