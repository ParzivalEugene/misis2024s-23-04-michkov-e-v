#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t, n, temp;
  std::cin >> t;
  while (t--) {
    std::vector<int> members;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> temp;
      members.push_back(temp);
    }

    std::vector<int> sortedMembers = members;
    std::sort(sortedMembers.begin(), sortedMembers.end());
    for (int i = 0; i < n; i++) {
      if (members[i] == sortedMembers[n - 1])
        std::cout << members[i] - sortedMembers[n - 2] << ' ';
      else
        std::cout << members[i] - sortedMembers[n - 1] << ' ';
    }
    std::cout << '\n';
  }
}