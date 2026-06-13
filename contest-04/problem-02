#include <bits/stdc++.h>
using namespace std;

long long count_comps(int u, int p, const vector<vector<int>> &adj,
                      long long min_sz, int &comps_count) {
  long long curr_subtree_sz = 1;

  for (int nei : adj[u]) {
    if (nei == p)
      continue;
    curr_subtree_sz += count_comps(nei, u, adj, min_sz, comps_count);
  }

  if (curr_subtree_sz >= min_sz) {
    comps_count++;
    return 0;
  }

  return curr_subtree_sz;
}

bool can_partition(long long mid, int n, int k,
                   const vector<vector<int>> &adj) {
  int comps_count = 0;
  count_comps(0, -1, adj, mid, comps_count);

  return comps_count >= k + 1;
}

void solve() {
  int n, k;
  if (!(cin >> n >> k))
    return;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  long long left = 1, right = n;
  long long res = 1;

  while (left <= right) {
    long long mid = left + (right - left) / 2;
    if (can_partition(mid, n, k, adj)) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << res << endl;
}

int main() {
  int t;
  if (!(cin >> t))
    return 0;
  while (t--) {
    solve();
  }

  return 0;
}