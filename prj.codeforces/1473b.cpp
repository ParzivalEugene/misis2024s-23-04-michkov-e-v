#include <algorithm>
#include <iostream>
#include <string>

std::string multiply(std::string s, int k) {
  std::string res = "";
  for (int i; i < k; i++) res += s;
  return res;
}

int main() {
  int n;
  std::string word1, word2, res;

  std::cin >> n;
  for (int i; i < n; i++) {
    std::cin >> word1 >> word2;
    int word1_len = word1.size(), word2_len = word2.size();
    int gcd = std::__gcd(word1_len, word2_len);
    res = multiply(word1, word2_len / gcd);
    if (res == multiply(word2, word1_len / gcd))
      std::cout << res << '\n';
    else
      std::cout << "-1\n";
  }
}