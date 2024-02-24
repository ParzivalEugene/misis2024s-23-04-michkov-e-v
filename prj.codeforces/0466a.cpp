// https://codeforces.com/problemset/problem/466/A
#include <iostream>

int main() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;

  int cost = 0;
  if (m * a <= b) {
    cost = n * a;
  } else {
    cost = (n / m) * b + std::min((n % m) * a, b);
  }

  std::cout << cost;
}