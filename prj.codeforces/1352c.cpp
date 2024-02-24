// https://codeforces.com/problemset/problem/1352/C
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    int need = (k - 1) / (n - 1);
    std::cout << k + need << '\n';
  }
}