#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

void workWithCString();

int main() {
  workWithCString();
  return 0;
}

const int MAX_STR_SIZE = 200;

void enterCString(char* input_str, int& pos) {
  cout << "Enter your string: ";
  cin.getline(input_str, MAX_STR_SIZE);
  cout << "Enter pos to divide: ";
  cin >> pos;
}

int getRealDividePos(char* str, int pos) {
  int str_size = strlen(str);
  for (int index = str_size - 1; index >= 0; --index) {
    if(str[index] == ' ' && index <= pos) {
      return index;
    }
  }
  return 0;
}

void fillDivideStr(char* input_str, char* result_str, int size, int step) {
  for (int index = 0; index < size; ++index) {
    result_str[index] = input_str[index + step];
  }
  result_str[size] = '\0';
}

void workWithCString() {
  char input_str[MAX_STR_SIZE];
  int divide_pos;
  enterCString(input_str, divide_pos);
  int str_size = strlen(input_str);

  int real_divide_pos = getRealDividePos(input_str, divide_pos);

  // ab cd efr fsdf bgfd rregdf

  char divide_str1[MAX_STR_SIZE], divide_str2[MAX_STR_SIZE];
  fillDivideStr(input_str, divide_str1, real_divide_pos, 0);
  fillDivideStr(input_str, divide_str2, str_size - real_divide_pos - 1, real_divide_pos + 1);

  cout << "Divide strings" << '\n';
  cout << "String 1: " << divide_str1 << '\n';
  cout << "String 2: " << divide_str2 << '\n';
}