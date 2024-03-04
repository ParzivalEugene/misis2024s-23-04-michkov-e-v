#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  int count = 0;
  while (n < m) {
    if (m % 2 == 0) {
      m /= 2;
    } else {
      m++;
    }
    count++;
  }
  std::cout << count + n - m << std::endl;
}