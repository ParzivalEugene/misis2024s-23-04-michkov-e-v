// https://codeforces.com/problemset/problem/281/A
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  s[0] = toupper(s[0]);
  std::cout << s;
}