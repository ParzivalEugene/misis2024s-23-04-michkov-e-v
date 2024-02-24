#include <iostream>
bool check(int year) {
  using std::cin, std::cout;
  int a, b, c, d;

  a = year % 10;
  b = year % 100 / 10;
  c = year % 1000 / 100;
  d = year / 1000;
  return a != b & a != c & a != d & b != c & b != d & c != d;
}

int main() {
  using std::cin, std::cout;
  int year;
  cin >> year;
  for (int i = year + 1; i < 9999; i++) {
    if (check(i)) {
      cout << i;
      return 0;
    }
  }
}