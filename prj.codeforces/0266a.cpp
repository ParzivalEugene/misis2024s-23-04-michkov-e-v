// https://codeforces.com/problemset/problem/266/A
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  char c;
  int count = 0;
  char previous = ' ';
  while (std::cin >> c) {
    if (c == previous) {
      ++count;
    }
    previous = c;
  }

  std::cout << count;
}