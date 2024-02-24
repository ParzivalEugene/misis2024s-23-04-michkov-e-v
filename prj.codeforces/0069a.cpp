#include <iostream>
#include <vector>

int main() {
  int n, x0, y0, z0, x(0), y(0), z(0);

  std::cin >> n;
  while (n--) {
    std::cin >> x0 >> y0 >> z0;
    x, y, z += x0, y0, z0;
  }
  std::cout << ((x == 0 && y == 0 && z == 0) ? "YES\n" : "NO\n");
}