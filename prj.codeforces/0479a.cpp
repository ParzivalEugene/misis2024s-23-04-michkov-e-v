#include <cmath>
#include <iostream>

int main() {
  int ans, a, b, c;
  std::cin >> a >> b >> c;
  ans = a + b + c;
  ans = std::max(ans, a * b * c);
  ans = std::max(ans, a * (b + c));
  ans = std::max(ans, (a + b) * c);
  std::cout << ans << '\n';
}