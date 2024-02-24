// https://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <string>

int main() {
  using std::cout, std::cin, std::string;

  string word;
  int len, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> word;

    len = word.length();
    if (len > 10) {
      cout << word[0] << len - 2 << word[len - 1] << "\n";
    } else {
      cout << word << "\n";
    }
  }
}