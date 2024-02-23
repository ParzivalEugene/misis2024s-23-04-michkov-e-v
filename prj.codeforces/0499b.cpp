#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::string> dict;
  int n, m;
  std::string word1, word2;

  std::cin >> n >> m;
  for (int i; i < m; i++) {
    std::cin >> word1 >> word2;
    dict[word1] = (word1.size() <= word2.size() ? word1 : word2);
  }

  for (int i; i < n; i++) {
    std::cin >> word1;
    std::cout << dict[word1] << (n - i != 1 ? ' ' : '\n');
  }
}