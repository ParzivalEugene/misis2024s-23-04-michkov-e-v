// https://codeforces.com/problemset/problem/492/B
#include <algorithm>
#include <iostream>

int main() {
  int n, l;
  std::cin >> n >> l;

  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a, a + n);

  double max = 0;
  for (int i = 0; i < n - 1; i++) {
    double d = (a[i + 1] - a[i]) / 2.0;
    if (d > max) {
      max = d;
    }
  }
  if (a[0] > max) {
    max = a[0];
  }
  if (l - a[n - 1] > max) {
    max = l - a[n - 1];
  }

  std::cout.precision(10);
  std::cout << std::fixed << max;
}