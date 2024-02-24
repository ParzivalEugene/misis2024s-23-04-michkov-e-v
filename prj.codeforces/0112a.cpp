// https://codeforces.com/problemset/problem/112/A
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string a, b;
  std::cin >> a >> b;
  std::transform(a.begin(), a.end(), a.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  std::transform(b.begin(), b.end(), b.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  if (a < b) {
    std::cout << -1 << "\n";
  } else if (a > b) {
    std::cout << 1 << "\n";
  } else {
    std::cout << 0 << "\n";
  }
  return 0;
}