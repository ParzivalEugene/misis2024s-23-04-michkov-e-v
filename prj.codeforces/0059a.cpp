#include <iostream>
#include <string>

int main() {
  std::string word;
  std::cin >> word;
  int upper = 0, lower = 0;

  for (int i = 0; i < word.length(); i++) {
    if (std::isupper(word[i]))
      upper++;
    else
      lower++;
  }

  if (upper > lower) {
    for (int i = 0; i < word.length(); i++) {
      std::cout << (char)std::toupper(word[i]);
    }
  } else {
    for (int i = 0; i < word.length(); i++) {
      std::cout << (char)std::tolower(word[i]);
    }
  }
  std::cout << '\n';

  return 0;
}