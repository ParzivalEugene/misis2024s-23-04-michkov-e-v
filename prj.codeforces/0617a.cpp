#include <iostream>

int main() {
  using std::cin;
  using std::cout;

  int distance, counter;
  cin >> distance;
  counter = 0;
  while (distance != 0) {
    if (distance >= 5) {
      distance -= 5;
      counter++;
    } else if (distance >= 4) {
      distance -= 4;
      counter++;
    } else if (distance >= 3) {
      distance -= 3;
      counter++;
    } else if (distance >= 2) {
      distance -= 2;
      counter++;
    } else if (distance >= 1) {
      distance -= 1;
      counter++;
    }
  }
  cout << counter << "\n";
}