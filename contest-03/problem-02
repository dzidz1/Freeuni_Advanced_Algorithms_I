#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[2][N], n;
vector<int> adj[N];
long long dp[2][N];

void dfs(int v, int p = -1) {
  dp[0][v] = dp[1][v] = 0;
  for (int u : adj[v]) {
    if (u == p)
      continue;
    dfs(u, v);

    long long choose_left = max(abs(a[0][v] - a[1][u]) + dp[1][u],
                                dp[0][u] + abs(a[0][v] - a[0][u]));
    dp[0][v] += choose_left;

    long long choose_right = max(abs(a[1][v] - a[1][u]) + dp[1][u],
                                 dp[0][u] + abs(a[1][v] - a[0][u]));
    dp[1][v] += choose_right;
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[0][i] >> a[1][i];
  }

  fill(adj + 1, adj + n + 1, vector<int>());
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  cout << max(dp[0][1], dp[1][1]) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}