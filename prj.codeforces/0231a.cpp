// https://codeforces.com/problemset/problem/231/A
#include <iostream>

int main() {
  int n, a, b, c, res = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> a >> b >> c;
    res += (a + b + c) > 1;
  }
  std::cout << res << "\n";
  return 0;
}