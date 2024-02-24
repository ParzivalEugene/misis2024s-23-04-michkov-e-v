// https://codeforces.com/problemset/problem/1873/D
#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::string line;
    std::cin >> n >> k;
    std::cin >> line;
    int res = 0;

    for (int i = 0; i < n; i++) {
      if (line[i] == 'B') {
        res++;
        i += k - 1;
      }
    }

    std::cout << res << '\n';
  }
  return 0;
}