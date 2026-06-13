#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> in_degree(n + 1, 0);
  set<int> ready;

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    in_degree[i] = k;
    if (k == 0)
      ready.insert(i);
    for (int j = 0; j < k; j++) {
      int prev;
      cin >> prev;
      adj[prev].push_back(i);
    }
  }

  int total_reads = 1;
  int processed_count = 0;
  int current_pos = 1;

  while (!ready.empty()) {
    auto it = ready.lower_bound(current_pos);

    if (it == ready.end()) {
      total_reads++;
      current_pos = 1;
      continue;
    }

    int u = *it;
    ready.erase(it);
    processed_count++;
    current_pos = u;

    for (int v : adj[u]) {
      in_degree[v]--;
      if (in_degree[v] == 0)
        ready.insert(v);
    }
  }

  if (processed_count == n)
    cout << total_reads << endl;
  else
    cout << -1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}