#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int w[n + 1];
    for (int i = 1; i <= n; i++) w[i] = w[i - 1] + int(s[i - 1] == 'W');
    int result = 1000000000;
    for (int i = k; i <= n; i++) result = std::min(result, w[i] - w[i - k]);
    std::cout << result << '\n';
  }
}