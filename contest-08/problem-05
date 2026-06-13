#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e15;

struct Edge {
  int to;
  ll cap;
  int rev;
};

vector<Edge> g[205];
int lv[205], pt[205];

void add_e(int u, int v, ll c) {
  g[u].push_back({v, c, (int)g[v].size()});
  g[v].push_back({u, 0, (int)g[u].size() - 1});
}

bool bfs(int s, int t) {
  memset(lv, -1, sizeof(lv));
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
  for (int &i = pt[v]; i < g[v].size(); i++) {
    Edge &e = g[v][i];
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
    memset(pt, 0, sizeof(pt));
    while (ll p = dfs(s, t, INF))
      flow += p;
  }
  return flow;
}

struct Card {
  int p, c, l;
} a[110];

bool isp[200005];

bool check(int mid, int n, ll k) {
  vector<Card> v;
  int best_one_idx = -1;

  for (int i = 1; i <= n; i++) {
    if (a[i].l > mid)
      continue;
    if (a[i].c == 1) {
      if (best_one_idx == -1 || a[i].p > a[best_one_idx].p) {
        best_one_idx = i;
      }
    } else {
      v.push_back(a[i]);
    }
  }
  if (best_one_idx != -1)
    v.push_back(a[best_one_idx]);

  ll sum_p = 0;
  int S = 0, T = (int)v.size() + 1;
  for (int i = 0; i <= T; i++)
    g[i].clear();

  for (int i = 0; i < (int)v.size(); i++) {
    sum_p += v[i].p;
    if (v[i].c % 2 != 0) {
      add_e(S, i + 1, (ll)v[i].p);
      for (int j = 0; j < (int)v.size(); j++) {
        if (v[j].c % 2 == 0 && isp[v[i].c + v[j].c]) {
          add_e(i + 1, j + 1, INF);
        }
      }
    } else {
      add_e(i + 1, T, (ll)v[i].p);
    }
  }
  return (sum_p - max_f(S, T)) >= k;
}

int main() {
  fill(isp + 2, isp + 200005, true);
  for (int i = 2; i * i <= 200000; i++) {
    if (isp[i]) {
      for (int j = i * i; j <= 200000; j += i)
        isp[j] = false;
    }
  }

  int n;
  ll k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p >> a[i].c >> a[i].l;
  }

  int low = 1, high = n, ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid, n, k)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << endl;
  return 0;
}