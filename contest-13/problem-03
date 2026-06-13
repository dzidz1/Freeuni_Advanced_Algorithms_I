#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
  int n;
  vector<vector<int>> tree;

  SegmentTree(int n) {
    this->n = n;
    tree.resize(4 * n);
  }

  void build(const vector<int> &b, int node, int start, int end) {
    if (start == end) {
      tree[node].push_back(b[start]);
      return;
    }
    int mid = start + (end - start) / 2;

    build(b, 2 * node, start, mid);
    build(b, 2 * node + 1, mid + 1, end);

    tree[node].resize(tree[2 * node].size() + tree[2 * node + 1].size());
    merge(tree[2 * node].begin(), tree[2 * node].end(),
          tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
          tree[node].begin());
  }

  int query(int node, int start, int end, int L, int R, int target_val) {
    if (end < L || start > R)
      return 0;

    if (start >= L && end <= R)
      return lower_bound(tree[node].begin(), tree[node].end(), target_val) -
             tree[node].begin();

    int mid = start + (end - start) / 2;
    int left_res = query(2 * node, start, mid, L, R, target_val);
    int right_res = query(2 * node + 1, mid + 1, end, L, R, target_val);

    return left_res + right_res;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1);
  vector<vector<int>> pos(100005);
  vector<int> b(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    int curr_type_cnt = pos[a[i]].size();
    if (curr_type_cnt >= k)
      b[i] = pos[a[i]][curr_type_cnt - k];
    else
      b[i] = -1;

    pos[a[i]].push_back(i);
  }

  SegmentTree seg(n);
  seg.build(b, 1, 1, n);

  int q;
  cin >> q;
  int last = 0;

  while (q--) {
    int x, y;
    cin >> x >> y;

    int l = ((x + last) % n) + 1;
    int r = ((y + last) % n) + 1;

    if (l > r)
      swap(l, r);

    last = seg.query(1, 1, n, l, r, l);
    cout << last << endl;
  }

  return 0;
}