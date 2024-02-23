#include <iostream>

int main() {
  int n, counter = 0;
  char c;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    if (c == 'A')
      counter++;
    else
      counter--;
  }

  std::cout << (counter > 0 ? "Anton" : (counter < 0 ? "Danik" : "Friendship")) << '\n';
  return 0;
}