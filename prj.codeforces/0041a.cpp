#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] != t[n - i - 1]) {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';

  return 0;
}