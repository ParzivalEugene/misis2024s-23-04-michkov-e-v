// https://codeforces.com/problemset/problem/1721/B
#include <iostream>

int main() {
  using std::cin, std::cout, std::min;
  int t, n, m, sx, sy, d;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m >> sx >> sy >> d;
    if (min(n - sx, sy - 1) <= d && min(sx - 1, m - sy) <= d) {
      cout << "-1\n";
    } else {
      cout << n + m - 2 << "\n";
    }
  }
}