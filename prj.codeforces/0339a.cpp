// https://codeforces.com/problemset/problem/339/A
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  char c;
  std::vector<int> v;

  while (std::cin >> c) {
    if (c != '+') {
      v.push_back(c - '0');
    }
  }

  std::sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << '+';
    }
  }
}