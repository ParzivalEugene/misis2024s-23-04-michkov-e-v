#include <iostream>

const int N = 110;
int n;
int a[N];
int main() {
  using std::cout, std::cin;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = a[1];
    for (int i = 2; i <= n; i++) res &= a[i];
    cout << res << "\n";
  }
  return 0;
}