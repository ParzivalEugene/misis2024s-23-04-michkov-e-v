#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  int count = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      count++;
      if (count == 7) {
        std::cout << "YES" << std::endl;
        return 0;
      }
    } else {
      count = 1;
    }
  }
  std::cout << "NO" << std::endl;
}