#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t, n, count;
  char task;

  std::cin >> t;
  while (t--) {
    std::vector<char> data;
    std::cin >> n;
    count = 0;
    while (n--) {
      std::cin >> task;
      if (std::find(data.begin(), data.end(), task) != data.end()) {
        count++;
      } else {
        count += 2;
        data.push_back(task);
      }
    }
    std::cout << count << '\n';
  }
}