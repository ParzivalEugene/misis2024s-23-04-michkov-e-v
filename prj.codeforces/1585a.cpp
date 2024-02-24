#include <iostream>
#include <vector>

int solve(std::vector<int> line, int n) {
  int height = 1;
  int days_without_water = 0;

  for (int i = 0; i < n; i++) {
    if (line[i] == 1) {
      if (days_without_water >= 2) {
        return -1;
      }
      if (i > 0 && line[i - 1] == 1) {
        height += 5;
      } else {
        height += 1;
      }
      days_without_water = 0;
    } else {
      days_without_water++;
      if (days_without_water >= 2) {
        return -1;
      }
    }
  }
  return height;
}

int main() {
  int t, n;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::vector<int> line(n);
    for (int i = 0; i < n; i++) {
      std::cin >> line[i];
    }
    std::cout << solve(line, n) << "\n";
  }
  return 0;
}
