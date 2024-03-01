#include <algorithm>
#include <iostream>
#include <vector>

void fillVector(std::vector<int> &data, int count) {
  int temp;
  for (int i = 0; i < count; i++) {
    std::cin >> temp;
    data.push_back(temp);
  }
}

int main() {
  int n, line;
  std::vector<int> firstData;
  std::cin >> n;
  fillVector(firstData, n);
  for (int i = 0; i < 2; i++) {
    std::vector<int> secondData;
    std::vector<int> diff;
    n--;
    fillVector(secondData, n);
    std::sort(firstData.begin(), firstData.end());
    std::sort(secondData.begin(), secondData.end());
    std::set_difference(firstData.begin(), firstData.end(), secondData.begin(),
                        secondData.end(), std::inserter(diff, diff.begin()));
    std::cout << diff[0] << '\n';
    std::swap(firstData, secondData);
  }
}