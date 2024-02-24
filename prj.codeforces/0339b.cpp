// https://codeforces.com/problemset/problem/339/B
#include <iostream>
#include <vector>

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<long long> a(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> a[i];
  }
  long long cur = 1, res = 0;
  for (long long i = 0; i < m; ++i) {
    if (a[i] >= cur) {
      res += a[i] - cur;
    } else {
      res += n - cur + a[i];
    }
    cur = a[i];
  }
  std::cout << res << "\n";
  return 0;
}