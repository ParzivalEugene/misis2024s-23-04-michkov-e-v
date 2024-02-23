#include "iostream"

int main() {
  int n, k, d;
  int dp[100][2];
  std::cin >> n >> k >> d;
  dp[0][0] = 1;
  dp[0][1] = 0;

  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = 0;
    for (int j = 1; j <= k; j++) {
      if (i - j < 0) break;
      if (j < d) {
        dp[i][0] += dp[i - j][0];
        dp[i][0] %= 1000000007;
        dp[i][1] += dp[i - j][1];
        dp[i][1] %= 1000000007;
      } else {
        dp[i][1] += dp[i - j][0];
        dp[i][1] %= 1000000007;
        dp[i][1] += dp[i - j][1];
        dp[i][1] %= 1000000007;
      }
    }
  }

  std::cout << dp[n][1] << '\n';
  return 0;
}