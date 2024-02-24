// https://codeforces.com/contest/136/problem/B
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::string convert_to_3(int n) {
  std::string res = "";
  while (n > 0) {
    res += std::to_string(n % 3);
    n /= 3;
  }
  return res;
}

int convert_to_10(std::string s) {
  int res = 0;
  std::reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    res += (s[i] - '0') * std::pow(3, i);
  }
  return res;
}

std::string add_leading_zeros(std::string s, int n) {
  while (s.length() < n) {
    s += "0";
  }
  return s;
}

int main() {
  int a, c, sub_res(0);
  std::string a3, c3, b3 = "";
  std::cin >> a >> c;

  a3 = convert_to_3(a);
  c3 = convert_to_3(c);

  if (a3.length() < c3.length()) {
    a3 = add_leading_zeros(a3, c3.length());
  } else {
    c3 = add_leading_zeros(c3, a3.length());
  }

  std::reverse(a3.begin(), a3.end());
  std::reverse(c3.begin(), c3.end());

  for (int i = 0; i < a3.length(); i++) {
    sub_res = (c3[i] - '0') - (a3[i] - '0');
    if (sub_res < 0) {
      sub_res = 3 - (a3[i] - '0') + (c3[i] - '0');
    }
    b3 += std::to_string(sub_res);
  }

  std::cout << convert_to_10(b3) << "\n";

  return 0;
}