#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> data;
  int n, count;
  std::string name;

  std::cin >> n;
  while (n--) {
    std::cin >> name;
    count = data.count(name);
    if (count > 0) {
      std::cout << name << data[name] << '\n';
      data[name] += 1;
    } else {
      std::cout << "OK\n";
      data[name] = 1;
    }
  }
}