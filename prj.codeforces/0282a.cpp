// https://codeforces.com/problemset/problem/282/A
#include <iostream>
#include <string>

int main() {
  int n, res(0);
  std::string s;
  std::cin >> n;

  while (n--) {
    std::cin >> s;
    if (s.find("++") != std::string::npos) {
      res++;
    } else {
      res--;
    }
  }

  std::cout << res << "\n";
  return 0;
}