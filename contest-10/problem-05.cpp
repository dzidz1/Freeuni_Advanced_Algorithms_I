#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
double expected_value = 0.0;

void dfs(int u, int p, int depth) {
  expected_value += 1.0 / depth;

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, depth + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 1);
  cout << fixed << setprecision(20) << expected_value << endl;

  return 0;
}