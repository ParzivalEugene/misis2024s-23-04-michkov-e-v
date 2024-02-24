#include <iostream>
#include <set>
#include <string>

int main() {
  std::set<char> lucky = {'4', '7'}, four = {'4'}, seven = {'7'};
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string str_i = std::to_string(i);
    std::set<char> char_set_i(str_i.begin(), str_i.end());
    if (char_set_i == lucky || char_set_i == four || char_set_i == seven) {
      if (n % i == 0) {
        std::cout << "YES\n";
        return 0;
      }
    }
  }
  std::cout << "NO\n";
  return 0;
}