#include <iostream>

int main() {
  int n, k, t, i, j, p, q;
  char res[304][304];
  std::cin >> t;
  while (t > 0) {
    t--;
    std::cin >> n >> k;
    if (k % n == 0) {
      std::cout << "0\n";
    } else {
      std::cout << "2\n";
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        res[i][j] = '0';
      }
      res[i][n] = 0;
    }
    p = 0;
    q = 0;
    while (k > 0) {
      k--;
      res[p][q] = '1';
      p++;
      q++;
      q %= n;
      if (p == n) {
        p = 0;
        q++;
        q %= n;
      }
    }
    for (i = 0; i < n; i++) {
      std::cout << res[i] << '\n';
    }
  }
}