#include <algorithm>
#include <iostream>
#include <string>

struct Info {
 public:
  int open, close, full;
  Info(int _open, int _close, int _full) {
    open = _open;
    close = _close;
    full = _full;
  }
  Info() {
    open = 0;
    close = 0;
    full = 0;
  }
};

Info merge(Info left, Info right) {
  Info res = Info(0, 0, 0);
  res.full = left.full + right.full + std::min(left.open, right.close);
  res.open = left.open + right.open - std::min(left.open, right.close);
  res.close = left.close + right.close - std::min(left.open, right.close);
  return res;
}
void build(int index, int low, int high, std::string& s, Info sequence[]) {
  if (low == high) {
    sequence[index] = Info(s[low] == '(', s[low] == ')', 0);
    return;
  }
  int mid = (low + high) / 2;
  build(2 * index + 1, low, mid, s, sequence);
  build(2 * index + 2, mid + 1, high, s, sequence);
  sequence[index] = merge(sequence[2 * index + 1], sequence[2 * index + 2]);
}
Info query(int index, int low, int high, int l, int r, Info sequence[]) {
  if (r < low || l > high) return Info();
  if (low >= l && high <= r) return sequence[index];

  int mid = (low + high) >> 1;
  Info left = query(2 * index + 1, low, mid, l, r, sequence);
  Info right = query(2 * index + 2, mid + 1, high, l, r, sequence);
  return merge(left, right);
}

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  Info sequence[4 * n];
  build(0, 0, n - 1, s, sequence);
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    r--;
    Info res = query(0, 0, n - 1, l, r, sequence);
    std::cout << res.full * 2 << '\n';
  }
}