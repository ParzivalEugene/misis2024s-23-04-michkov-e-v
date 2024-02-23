#include <iostream>
#include <string>

int textToNumber(std::string &s) {
  int result = 0;
  for (int i = 0; i < s.length(); i++) {
    result = result * 26 + (s[i] - 'A' + 1);
  }
  return result;
}

std::string numberToText(int n) {
  std::string result;
  while (n > 0) {
    int r = n % 26;
    if (r == 0) {
      result = 'Z' + result;
      n = n / 26 - 1;
    } else {
      result = (char)('A' + r - 1) + result;
      n = n / 26;
    }
  }
  return result;
}

int main() {
  int n;
  std::string s;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    if (s[0] == 'R' && isdigit(s[1]) && s.find('C') != std::string::npos) {
      int c = s.find('C');
      std::string row = s.substr(1, c - 1);
      std::string col = s.substr(c + 1);
      std::cout << numberToText(std::stoi(col)) << row << '\n';
    } else {
      int j = 0;
      while (j < s.length() && !isdigit(s[j])) {
        j++;
      }
      std::string col = s.substr(0, j);
      std::string row = s.substr(j);
      std::cout << "R" << row << "C" << textToNumber(col) << '\n';
    }
  }
}