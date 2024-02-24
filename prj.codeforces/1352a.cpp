#include <iostream>
#include <vector>

int main() {
  using std::cin, std::cout, std::endl, std::vector;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> round_numbers;
    int power_of_10 = 1;

    while (n > 0) {
      int digit = n % 10;
      if (digit > 0) {
        round_numbers.push_back(digit * power_of_10);
      }
      n /= 10;
      power_of_10 *= 10;
    }

    cout << round_numbers.size() << endl;
    for (int i = 0; i < round_numbers.size(); i++) {
      cout << round_numbers[i] << " ";
    }
    cout << endl;
  }

  return 0;
}