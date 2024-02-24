#include <iostream>
#include <string>

int main() {
  std::string word, res = "", alpha = "aoyeuiAOYEUI";
  std::cin >> word;

  for (char item : word) {
    if (alpha.find(item) == std::string::npos) {
      res += '.';
      res += std::tolower(item);
    }
  }

  std::cout << res << '\n';
}