#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree {
  int size;
  vector<int> tree;

  FenwickTree(int n) {
    size = n;
    tree.assign(n + 1, 0);
  }

  void update(int idx, int val) {
    for (; idx <= size; idx += idx & -idx) {
      tree[idx] += val;
    }
  }

  int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
      sum += tree[idx];
    }
    return sum;
  }
};

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> vals(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vals[i] = a[i];
  }

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
  }

  int num_distinct = vals.size();
  vector<int> cnt(num_distinct, 0);
  vector<int> l(n), r(n);

  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    l[i] = cnt[a[i]];
  }

  fill(cnt.begin(), cnt.end(), 0);

  for (int i = n - 1; i >= 0; i--) {
    cnt[a[i]]++;
    r[i] = cnt[a[i]];
  }

  FenwickTree bit(n);
  ll total_pairs = 0;
  for (int i = n - 1; i >= 0; i--) {
    total_pairs += bit.query(l[i] - 1);
    bit.update(r[i], 1);
  }

  cout << total_pairs << endl;

  return 0;
}