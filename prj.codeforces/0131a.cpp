#include <iostream>
#include <string>

bool is_upper(std::string word) {
  for (char c : word) {
    if (std::islower(c)) {
      return false;
    }
  }
  return true;
}

bool is_reverse_capitalized(std::string word) {
  if (std::isupper(word[0])) {
    return false;
  }

  for (char c : word.substr(1, word.length() - 1)) {
    if (std::islower(c)) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string word;
  std::cin >> word;
  if (is_upper(word)) {
    for (char c : word) {
      std::cout << (char)std::tolower(c);
    }
    std::cout << '\n';
    return 0;
  }
  if (is_reverse_capitalized(word)) {
    std::cout << (char)std::toupper(word[0]);
    for (char c : word.substr(1, word.length() - 1)) {
      std::cout << (char)std::tolower(c);
    }
    std::cout << '\n';
    return 0;
  }
  std::cout << word << '\n';
}