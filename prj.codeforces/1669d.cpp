// https://codeforces.com/problemset/problem/1669/D

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> substrings;
  std::string substring;
  for (char c : str) {
    if (c == delimiter) {
      substrings.push_back(substring);
      substring.clear();
    } else {
      substring += c;
    }
  }
  substrings.push_back(substring);
  return substrings;
}

bool solve() {
  int n;
  std::string line;
  std::vector<std::string> sub_lines;

  std::cin >> n;
  std::cin >> line;

  sub_lines = split(line, 'W');
  for (std::string sub_line : sub_lines) {
    if (sub_line.length() == 0) {
      continue;
    }
    bool b = sub_line.find("B") != std::string::npos;
    bool r = sub_line.find("R") != std::string::npos;

    if (b ^ r) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
}