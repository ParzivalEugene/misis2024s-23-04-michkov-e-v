// https://codeforces.com/problemset/problem/236/A
#include <iostream>

int main() {
  char c;
  int count = 0;
  bool letters[26] = {false};

  while (std::cin >> c) {
    if (!letters[c - 'a']) {
      letters[c - 'a'] = true;
      ++count;
    }
  }

  if (count % 2 == 0) {
    std::cout << "CHAT WITH HER!";
  } else {
    std::cout << "IGNORE HIM!";
  }
}