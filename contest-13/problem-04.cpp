#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_X = 200005;

struct Node {
  ll sum_k;
  ll sum_m;
  int left_child;
  int right_child;

  Node() : sum_k(0), sum_m(0), left_child(0), right_child(0) {}
};

vector<Node> tree_nodes;

int create_node(ll k = 0, ll m = 0, int l = 0, int r = 0) {
  Node new_node;
  new_node.sum_k = k;
  new_node.sum_m = m;
  new_node.left_child = l;
  new_node.right_child = r;
  tree_nodes.push_back(new_node);
  return tree_nodes.size() - 1;
}

int update(int prev_root, int start, int end, int idx, ll delta_k, ll delta_m) {
  int new_root = create_node(tree_nodes[prev_root].sum_k + delta_k,
                             tree_nodes[prev_root].sum_m + delta_m,
                             tree_nodes[prev_root].left_child,
                             tree_nodes[prev_root].right_child);

  if (start == end) {
    return new_root;
  }

  int mid = start + (end - start) / 2;
  if (idx <= mid) {
    int next_left = update(tree_nodes[prev_root].left_child, start, mid, idx,
                           delta_k, delta_m);
    tree_nodes[new_root].left_child = next_left;
  } else {
    int next_right = update(tree_nodes[prev_root].right_child, mid + 1, end,
                            idx, delta_k, delta_m);
    tree_nodes[new_root].right_child = next_right;
  }

  return new_root;
}

pair<ll, ll> query(int root, int start, int end, int target_idx) {
  if (root == 0 || target_idx < start) {
    return {0, 0};
  }

  if (end <= target_idx) {
    return {tree_nodes[root].sum_k, tree_nodes[root].sum_m};
  }

  int mid = start + (end - start) / 2;
  pair<ll, ll> left_res =
      query(tree_nodes[root].left_child, start, mid, target_idx);

  pair<ll, ll> right_res = {0, 0};
  if (target_idx > mid) {
    right_res = query(tree_nodes[root].right_child, mid + 1, end, target_idx);
  }

  return {left_res.first + right_res.first, left_res.second + right_res.second};
}

int main() {
  int n;
  cin >> n;
  tree_nodes.push_back(Node());
  vector<int> roots(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    ll x1, x2, y1, a, b, y2;
    cin >> x1 >> x2 >> y1 >> a >> b >> y2;

    int current_root = roots[i - 1];
    current_root = update(current_root, 0, MAX_X, 0, 0, y1);
    current_root = update(current_root, 0, MAX_X, x1 + 1, a, b - y1);
    current_root = update(current_root, 0, MAX_X, x2 + 1, -a, y2 - b);

    roots[i] = current_root;
  }

  int m;
  cin >> m;
  ll last = 0;

  while (m--) {
    ll l, r, encrypted_x;
    cin >> l >> r >> encrypted_x;

    ll x0 = (encrypted_x + last) % 1000000000LL;

    int query_idx = min((ll)MAX_X, x0);

    pair<ll, ll> res_r = query(roots[r], 0, MAX_X, query_idx);
    pair<ll, ll> res_l = query(roots[l - 1], 0, MAX_X, query_idx);

    ll net_k = res_r.first - res_l.first;
    ll net_m = res_r.second - res_l.second;

    last = x0 * net_k + net_m;
    cout << last << endl;
  }

  return 0;
}