#include <iostream>

int main() {
  int n, a, b, maxCapacity = 0, capacity = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> a >> b;
    capacity += -a + b;
    if (maxCapacity < capacity) maxCapacity = capacity;
  }
  std::cout << maxCapacity << '\n';
}