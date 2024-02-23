#include <iostream>
#include <set>
#include <string>

int main() {
  int n;
  char c;
  std::set<char> data;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    data.insert(std::tolower(c));
  }

  std::cout << (data.size() == 26 ? "YES" : "NO") << '\n';
}