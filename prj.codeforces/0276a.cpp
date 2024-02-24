#include <iostream>
#include <vector>

int main() {
  using std::cin, std::cout, std::endl, std::vector, std::pair;
  int n, k;
  cin >> n >> k;

  /* https://en.cppreference.com/w/cpp/utility/pair
  Понял так: тапл который хранит два элемента
  Почему заюзал? Потому что учу плюшки нового языка и пытаюсь освоить новые
  структуры Почему не тапл? Вроде как pair в случае с двумя элементами
  эффективнее
  */
  vector<pair<int, int>> restaurants(n);
  for (int i = 0; i < n; i++) {
    cin >> restaurants[i].first >> restaurants[i].second;
  }
  int max_pleasure = -1000000000;
  for (int i = 0; i < n; i++) {
    int pleasure;
    if (restaurants[i].second > k) {
      pleasure = restaurants[i].first - (restaurants[i].second - k);
    } else {
      pleasure = restaurants[i].first;
    }
    if (pleasure > max_pleasure) {
      max_pleasure = pleasure;
    }
  }
  cout << max_pleasure << endl;
  return 0;
}