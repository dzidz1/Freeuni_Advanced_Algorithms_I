#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
char res[N];
vector<int> g[N];
int sz[N];
bool dead[N];

void pre_dfs(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == par || dead[u])
      continue;
    pre_dfs(u, v);
    sz[v] += sz[u];
  }
}

int find_centroid(int num, int v, int par = -1) {
  for (int u : g[v]) {
    if (u != par && !dead[u] && 2 * sz[u] > num) {
      return find_centroid(num, u, v);
    }
  }
  return v;
}

void solve(int v, char current_char) {
  pre_dfs(v);
  int cent = find_centroid(sz[v], v);

  res[cent] = current_char;
  dead[cent] = true;

  for (int u : g[cent]) {
    if (!dead[u]) {
      solve(u, current_char + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  solve(0, 'A');

  for (int i = 0; i < n; i++) {
    cout << res[i] << ' ';
  }
  cout << endl;

  return 0;
}