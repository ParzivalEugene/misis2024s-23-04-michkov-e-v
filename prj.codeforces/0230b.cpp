#include <iostream>
#include <set>

const int sqrt_lim = 1000001;

std::set<long long> prime_squares() {
  static bool arr[sqrt_lim];

  for (int i = 2; i * i < sqrt_lim; i++) {
    if (!arr[i]) {
      for (int j = i * i; j < sqrt_lim; j += i) {
        arr[j] = true;
      }
    }
  }

  std::set<long long> res;
  for (int i = 2; i < sqrt_lim; i++) {
    if (!arr[i]) res.insert((long long)i * i);
  }
  return res;
}

int main() {
  std::set<long long> sq(prime_squares());

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    std::cin >> x;

    if (sq.find(x) != sq.end()) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}