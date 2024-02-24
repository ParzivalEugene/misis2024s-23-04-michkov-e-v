// https://codeforces.com/problemset/problem/1670/B
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector, std::cin, std::cout, std::ios, std::find;

int solve(string& s, const vector<char>& symbols, int n) {
  int res(0), last(0);
  for (int i = 0; i < n; i++) {
    if (find(symbols.begin(), symbols.end(), s[i]) != symbols.end()) {
      if (i - last > res) {
        res = i - last;
      }
      last = i;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, k;
  string s;
  vector<char> symbols;
  char symbol;

  cin >> t;
  for (int i = 0; i < t; i++) {
    symbols.clear();
    cin >> n;
    cin >> s;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> symbol;
      symbols.push_back(symbol);
    }

    cout << solve(s, symbols, n) << '\n';
  }

  return 0;
}