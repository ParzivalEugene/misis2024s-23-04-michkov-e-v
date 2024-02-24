#include <algorithm>
#include <iostream>
#include <string>
using std::cin, std::cout, std::ios_base, std::max, std::string;

int n, k, t;
string s;

int main() {
  ios_base::sync_with_stdio(false);  // Отключаем синхронизацию stdio и iostream
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    int zeros = 0, ones = 0;
    bool check = true;
    for (int i = 0; i < k; i++) {
      int tmp = -1;
      for (int j = i; j < n; j += k) {
        if (s[j] != '?') {
          if (tmp != -1 && s[j] - '0' != tmp) {
            check = false;
            break;
          }
          tmp = s[j] - '0';
        }
      }
      if (tmp != -1) {
        (tmp == 0 ? zeros : ones)++;
      }
    }
    if (max(zeros, ones) > k / 2) {
      check = false;
    }
    cout << (check ? "YES\n" : "NO\n");
  }
}