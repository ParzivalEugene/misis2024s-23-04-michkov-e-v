#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> m;
  std::string s;
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> s;
    m[s]++;
  }

  int maxValue = -1;
  std::string maxKey;
  for (const auto& pair: m) {
    if (pair.second > maxValue) {
      maxValue = pair.second;
      maxKey = pair.first;
    }
  }

  std::cout << maxKey << std::endl;

  return 0;
}