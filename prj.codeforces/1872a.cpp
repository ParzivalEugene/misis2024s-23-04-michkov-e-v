// https://codeforces.com/problemset/problem/1872/A
#include <iostream>

int pour(double &vessel_a, double &vessel_b, double cup) {
  using std::cout;

  double diff;
  int moves = 0;

  if (vessel_a == vessel_b) {
    return 0;
  }

  if (vessel_b > vessel_a) {
    // aka a, b = b, a; вроде работает как кортежное приравнивание в питоне
    std::swap(vessel_a, vessel_b);
  }

  while (vessel_a > vessel_b) {
    diff = vessel_a - vessel_b;
    if (diff > cup) {
      vessel_a -= cup;
      vessel_b += cup;
      moves++;
    } else if (diff == cup) {
      vessel_a -= cup;
      vessel_b += cup;
      return ++moves;
    } else {
      vessel_a -= diff / 2;
      vessel_b += diff / 2;
      return ++moves;
    }
  }
  return moves;
}

int main() {
  using std::cout, std::cin;
  int t;
  double vessel_a, vessel_b, cup;

  for (cin >> t; t; t--) {
    cin >> vessel_a >> vessel_b >> cup;
    cout << pour(vessel_a, vessel_b, cup) << '\n';
  }
}