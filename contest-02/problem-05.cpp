#include <bits/stdc++.h>
using namespace std;

long long a[200005], b[200005], c[200005];
vector<int> g[200005];
long long cost = 0;

pair<long long, long long> dfs(int u, int par, long long mn) {
  pair<long long, long long> as = {0, 0};
  if (b[u] != c[u]) {
    if (b[u])
      as.first++;
    else
      as.second++;
  }

  for (auto &it : g[u]) {
    if (it == par)
      continue;
    pair<long long, long long> p = dfs(it, u, min(mn, a[u]));
    as.first += p.first;
    as.second += p.second;
  }

  if (a[u] < mn) {
    long long take = min(as.first, as.second);
    cost += 2 * take * a[u];
    as.first -= take;
    as.second -= take;
  }

  return as;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  pair<long long, long long> res = dfs(1, 0, 2000000000LL);

  if (res.first || res.second)
    cout << -1;
  else
    cout << cost;

  return 0;
}