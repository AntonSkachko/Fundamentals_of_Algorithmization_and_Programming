#include <iostream>
#include <cstring>
using std::cin;
using std::cout;

void workWithCString();

int main() {
  workWithCString();
  return 0;
}

const int MAX_STR_SIZE = 150;

void getFullStr(char* str) {
  cout << "Enter str:\n";
  cin.getline(str, MAX_STR_SIZE);
}

bool isNotWord(char c) {
  return (!(c <= 'Z' && c >= 'A') && !(c <= 'z' && c >= 'a')
      && !(c <= '9' && c >= '0'));
}

int findStartWordPos(char* str, int word_index) {
  if (word_index == 1) {
    return 0;
  }
  int str_size = strlen(str);
  int cur_word_index = 1;
  int index = 0;
  while(isNotWord(str[index]) && index < str_size) {
    ++index;
  }
  while (index < str_size) {
    if (isNotWord(str[index])) {
      cur_word_index++;
      while (isNotWord(str[index]) && index < str_size) {
        ++index;
      }
      if (cur_word_index == word_index) {
        return index;
      }
      continue;
    }
    ++index;
  }
  return -1;
}

int findEndWordPos(char* str, int word_index) {
  int str_size = strlen(str);
  int cur_word_index = 0;
  int index = 0;
  while(isNotWord(str[index]) && index < str_size) {
    ++index;
  }
  while(index < str_size) {
    if (isNotWord(str[index])) {
      cur_word_index++;
      if (cur_word_index == word_index) {
        return index - 1;
      }
      while (isNotWord(str[index]) && index < str_size) {
        ++index;
      }
      continue;
    }
    index++;
  }
  if (cur_word_index + 1 == word_index) {
    return str_size - 1;
  }
  return -1;
}

void fillDivideStr(char* input_str, char* result_str, int size, int step) {
  for (int index = 0; index < size; ++index) {
    result_str[index] = input_str[index + step];
  }
  result_str[size] = '\0';
}

void eraseStr(char* str) {
  for (int i = 0; i < MAX_STR_SIZE; ++i) {
    str[i] = '\0';
  }
}

void fillResultStr(char* str, char* result, int FIRST_WORD, int LAST_WORD) {
  eraseStr(result);
  char word[MAX_STR_SIZE];

  for (int cur_word = FIRST_WORD; cur_word <= LAST_WORD; ++cur_word) {
    int first_pos = findStartWordPos(str, cur_word);
    int second_pos = findEndWordPos(str, cur_word);

    eraseStr(word);
    fillDivideStr(str, word, second_pos - first_pos + 1, first_pos);

    if(cur_word != FIRST_WORD) {
      strcat(result, " ");
    }
    strcat(result, word);
  }
}

void workWithCString() {
  char str[MAX_STR_SIZE];
  getFullStr(str);
  // frei,   rgejgi: gerigjier,    gergere! 235? 523, fewf, fre.

  const int FIRST_WORD = 2;
  const int LAST_WORD = 4;

  int check_pos = findEndWordPos(str, LAST_WORD);
  if (check_pos == -1) {
    cout << "There no are fourth word\n";
    return;
  }
  char result[MAX_STR_SIZE];
  fillResultStr(str, result, FIRST_WORD, LAST_WORD);
  cout << "Result str: " << result << '\n';
}