#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::cin, std::cout, std::map, std::vector, std::sort;

int main() {
  int n;
  int x, y;
  map<int, int> computers;
  vector<int> keys;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    computers[x] = y;
    keys.push_back(x);
  }

  sort(keys.begin(), keys.end());

  for (int i = 0; i < n - 1; i++) {
    if (computers[keys[i]] > computers[keys[i + 1]]) {
      cout << "Happy Alex" << '\n';
      return 0;
    }
  }
  cout << "Poor Alex" << '\n';
}