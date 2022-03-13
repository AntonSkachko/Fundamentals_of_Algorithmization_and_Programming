#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::swap;
using std::string;

void workWithCString();
void workWithString();

int main() {
  workWithCString();
  workWithString();
  return 0;
}

void workWithCString() {
  const int MAX_STR_SIZE = 200;
  char str[MAX_STR_SIZE];
  cout << "Enter str:\n";
  cin.getline(str, MAX_STR_SIZE);
  int size = strlen(str);
  cout << "Str length = " << size << '\n';
  if(size % 4 == 0) {
    int mid = size / 2;
    for (int index = 0; index < mid; ++index) {
      swap(str[index], str[index + mid]);
    }
    cout << "Result str: " << str << '\n';
  }
}

void workWithString() {
  string str;
  cout << "Enter str:\n";
  getline(cin, str);
  int size = str.length();
  cout << "Str length = " << size << '\n';
  if(size % 4 == 0) {
    int mid = size / 2;
    for (int index = 0; index < mid; ++index) {
      swap(str[index], str[index + mid]);
    }
    cout << "Result str: " << str << '\n';
  }
}
