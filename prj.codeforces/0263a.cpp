// https://codeforces.com/problemset/problem/263/A
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  using std::cin, std::cout, std::endl, std::vector, std::abs;
  vector<vector<int>> matrix(5, vector<int>(5));
  int x, y;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1) {
        x = i;
        y = j;
      }
    }
  }

  int moves = abs(x - 2) + abs(y - 2);

  cout << moves << endl;

  return 0;
}