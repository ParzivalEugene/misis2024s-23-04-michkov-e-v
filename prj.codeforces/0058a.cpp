// https://codeforces.com/problemset/problem/58/A
#include <iostream>
#include <string>

int main() {
  std::string word, hello = "hello";
  std::cin >> word;

  int i = 0;
  for (char item : word) {
    if (item == hello[i]) {
      i++;
    }
  }

  std::cout << ((i == 5) ? "YES\n" : "NO\n");
}