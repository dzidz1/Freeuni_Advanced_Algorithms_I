#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> adj[n + 1];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n == 1) {
    cout << "Ayush" << endl;
    return;
  }
  if (adj[x].size() == 1) {
    cout << "Ayush" << endl;
  } else {
    if (n % 2)
      cout << "Ashish" << endl;
    else
      cout << "Ayush" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}