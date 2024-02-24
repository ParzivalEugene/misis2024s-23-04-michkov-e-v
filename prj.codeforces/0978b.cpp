// https://codeforces.com/problemset/problem/978/B
#include <iostream>
#include <string>

int main() {
  using std::cin, std::cout, std::string;

  int x_counter, result = 0;
  string line;

  cin >> x_counter;
  cin >> line;
  x_counter = 0;

  for (int i = 0; i < line.size(); i++) {
    if (line[i] == 'x') {
      x_counter++;
      if (x_counter > 2) {
        result++;
      }
    } else {
      x_counter = 0;
    }
  }
  cout << result << "\n";
}