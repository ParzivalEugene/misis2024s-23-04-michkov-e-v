#include <algorithm>
#include <iostream>
#include <stack>

const int MAX = 3e5 + 10;
const int INFINITY = 1e9 + 10;

struct SegmentTree {
  std::pair<int, int> tree[4 * MAX];
  int lazy[4 * MAX];

  void build(int node, int left, int right) {
    tree[node] = {INFINITY, right - left + 1};
    if (left == right) return;

    int middle = (left + right) >> 1;

    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
  }

  void flush(int node, int left, int right) {
    if (!lazy[node]) return;

    if (left != right)
      lazy[2 * node] += lazy[node], lazy[2 * node + 1] += lazy[node];

    tree[node].first += lazy[node];
    lazy[node] = 0;
  }

  void update(int node, int left, int right, int data, int b, int v) {
    flush(node, left, right);
    if (left > right || left > b || right < data) return;

    if (left >= data && right <= b) {
      lazy[node] = v;
      flush(node, left, right);
      return;
    }

    int middle = (left + right) >> 1;

    update(2 * node, left, middle, data, b, v);
    update(2 * node + 1, middle + 1, right, data, b, v);

    tree[node].first = std::min(tree[2 * node].first, tree[2 * node + 1].first);
    tree[node].second = 0;

    if (tree[2 * node].first == tree[node].first)
      tree[node].second += tree[2 * node].second;
    if (tree[2 * node + 1].first == tree[node].first)
      tree[node].second += tree[2 * node + 1].second;
  }
} segmentTree;

int data[MAX];

int main(void) {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    data[y] = x;
  }

  segmentTree.build(1, 1, n);

  long long res = 0;
  std::stack<std::pair<int, int>> stackX, stackY;

  for (int i = 1; i <= n; i++) {
    segmentTree.update(1, 1, n, 1, i - 1, -1);
    segmentTree.update(1, 1, n, i, i, -INFINITY);

    while (stackX.size() && stackX.top().first < data[i]) {
      int right = stackX.top().second, mx = stackX.top().first;
      stackX.pop();

      int left = (stackX.size() ? stackX.top().second + 1 : 1);

      segmentTree.update(1, 1, n, left, right, data[i] - mx);
    }

    while (stackY.size() && stackY.top().first > data[i]) {
      int right = stackY.top().second, mn = stackY.top().first;
      stackY.pop();

      int left = (stackY.size() ? stackY.top().second + 1 : 1);

      segmentTree.update(1, 1, n, left, right, mn - data[i]);
    }

    stackX.push({data[i], i});
    stackY.push({data[i], i});

    segmentTree.flush(1, 1, n);
    res += 1ll * segmentTree.tree[1].second;
  }

  std::cout << res << std::endl;
}