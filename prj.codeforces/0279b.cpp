#include <iostream>

int main() {
  int n, t;
  std::cin >> n >> t;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int max = 0;
  int sum = 0;
  for (int i = 0, j = 0; j < n; j++) {
    sum += a[j];
    while (sum > t) {
      sum -= a[i];
      i++;
    }
    if (j - i + 1 > max) {
      max = j - i + 1;
    }
  }
  std::cout << max << std::endl;
}