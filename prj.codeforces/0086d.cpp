#include <algorithm>
#include <iostream>

const int MAXN = 1e6 + 50;
int values[MAXN];
long long counter[MAXN];
long long res = 0;
long long ans[MAXN];

struct Query {
  int left, right, index;
  bool operator<(Query other) const {
    int v1 = left / 500, v2 = other.left / 500;
    if (v1 != v2) return v1 < v2;
    return v1 & 1 ? (right < other.right) : (right > other.right);
  }
} query[MAXN];

void remove(int index) {
  int v = values[index];
  long long count = counter[v];
  res -= count * count * v;
  counter[v] = --count;
  res += count * count * v;
}

void add(int index) {
  int v = values[index];
  long long count = counter[v];
  res -= count * count * v;
  counter[v] = ++count;
  res += count * count * v;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, t;
  std::cin >> n >> t;

  for (int i = 0; i < n; i++) std::cin >> values[i];
  for (int i = 0; i < t; i++) {
    std::cin >> query[i].left >> query[i].right;
    query[i].left--;
    query[i].right--;
    query[i].index = i;
  }
  std::sort(query, query + t);
  int currentLeft = 0, currentRight = -1;
  for (int i = 0; i < t; i++) {
    Query q = query[i];
    while (currentLeft > q.left) add(--currentLeft);
    while (currentRight < q.right) add(++currentRight);
    while (currentLeft < q.left) remove(currentLeft++);
    while (currentRight > q.right) remove(currentRight--);
    ans[q.index] = res;
  }

  for (int i = 0; i < t; i++) std::cout << ans[i] << '\n';
}