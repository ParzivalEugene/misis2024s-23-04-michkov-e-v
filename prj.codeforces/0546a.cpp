#include <iostream>

int main() {
  int k, n, w;
  std::cin >> k >> n >> w;
  int cost = k * w * (w + 1) / 2;
  std::cout << (cost > n ? cost - n : 0) << std::endl;
}