// https://codeforces.com/problemset/problem/978/A
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using std::cout, std::cin, std::vector, std::find, std::reverse;

  vector<int> numbers;
  vector<int> safe;
  int n, number;

  for (cin >> n; n; n--) {
    cin >> number;
    numbers.push_back(number);
  }

  // разворачивает вектор [1, 2, 3] -> [3, 2, 1]
  reverse(numbers.begin(), numbers.end());

  for (int x : numbers) {
    // find возвращает индекс элемента, если он есть в векторе, иначе -1
    if (!(find(safe.begin(), safe.end(), x) != safe.end())) {
      safe.push_back(x);
    }
  }

  reverse(safe.begin(), safe.end());
  cout << safe.size() << "\n";
  for (int x : safe) {
    cout << x << ' ';
  }
  cout << "\n";
  return 0;
}