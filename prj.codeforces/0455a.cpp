#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> dp(100001, 0);
  std::vector<int> count(100001, 0);
  std::vector<int> inp(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> inp[i];
    count[inp[i]]++;
  }

  if (inp.size() == n) {
    dp[1] = count[1];
    for (int i = 2; i <= 100000; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + (long long)i * count[i]);
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}