#include <iostream>

int main() {
  int count = 0;
  long long n;
  std::cin >> n;
  while (n) {
    if (n % 10 == 4 || n % 10 == 7) count++;
    n /= 10;
  }
  if (count == 0) {
    std::cout << "NO" << '\n';
    return 0;
  }
  while (count) {
    if (!(count % 10 == 4 || count % 10 == 7)) {
      std::cout << "NO" << '\n';
      return 0;
    };
    count /= 10;
  }
  std::cout << "YES" << '\n';
}