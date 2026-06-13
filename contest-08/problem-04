#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
  int to;
  ll cap;
  int rev;
};

vector<vector<Edge>> g;
vector<int> lv, pt;

void add_e(int u, int v, ll c) {
  g[u].push_back({v, c, (int)g[v].size()});
  g[v].push_back({u, 0, (int)g[u].size() - 1});
}

bool bfs(int s, int t) {
  fill(lv.begin(), lv.end(), -1);
  lv[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto &e : g[v]) {
      if (e.cap > 0 && lv[e.to] == -1) {
        lv[e.to] = lv[v] + 1;
        q.push(e.to);
      }
    }
  }
  return lv[t] != -1;
}

ll dfs(int v, int t, ll f) {
  if (!f || v == t)
    return f;
  for (int &i = pt[v]; i < g[v].size(); ++i) {
    auto &e = g[v][i];
    if (lv[v] + 1 != lv[e.to] || !e.cap)
      continue;
    ll p = dfs(e.to, t, min(f, e.cap));
    if (!p)
      continue;
    e.cap -= p;
    g[e.to][e.rev].cap += p;
    return p;
  }
  return 0;
}

ll max_f(int s, int t) {
  ll flow = 0;
  while (bfs(s, t)) {
    fill(pt.begin(), pt.end(), 0);
    while (ll p = dfs(s, t, INF))
      flow += p;
  }
  return flow;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  map<int, int> pr;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (int d = 2; d * d <= x; d++) {
      if (x % d == 0) {
        pr[d] = 1;
        while (x % d == 0)
          x /= d;
      }
    }
    if (x > 1)
      pr[x] = 1;
  }

  map<pair<int, int>, int> id;
  int cur = 2;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (auto const &[p, _] : pr) {
      if (x % p == 0) {
        id[{i, p}] = cur++;
      }
    }
  }

  g.resize(cur);
  lv.resize(cur);
  pt.resize(cur);

  for (auto const &[k, node] : id) {
    int idx = k.first, p = k.second, x = a[idx], cnt = 0;
    while (x % p == 0) {
      x /= p;
      cnt++;
    }
    if (idx % 2)
      add_e(0, node, cnt);
    else
      add_e(node, 1, cnt);
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u % 2 == 0)
      swap(u, v);
    for (auto const &[p, _] : pr) {
      if (id.count({u, p}) && id.count({v, p})) {
        add_e(id[{u, p}], id[{v, p}], INF);
      }
    }
  }

  cout << max_f(0, 1) << endl;
  return 0;
}