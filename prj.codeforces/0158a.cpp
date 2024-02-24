// https://codeforces.com/problemset/problem/158/A
#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= a[k - 1] && a[i] > 0) {
      count++;
    }
  }
  std::cout << count << "\n";
  return 0;
}