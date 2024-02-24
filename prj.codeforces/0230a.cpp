// https://codeforces.com/problemset/problem/230/A
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int s, n;
  std::cin >> s >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;
  std::sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (s > v[i].first)
      s += v[i].second;
    else {
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES";
  return 0;
}