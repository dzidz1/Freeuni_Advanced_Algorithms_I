#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<set<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  vector<int> seq(n);
  for (int i = 0; i < n; i++)
    cin >> seq[i];

  if (seq[0] != 1) {
    cout << "No" << endl;
    return 0;
  }

  int idx = 1;
  queue<int> q;
  vector<bool> visited(n + 1, false);
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    int unvis_neis = 0;
    for (int nei : adj[top]) {
      if (!visited[nei])
        unvis_neis++;
    }

    for (int i = 0; i < unvis_neis; i++) {
      if (idx < n && adj[top].find(seq[idx]) != adj[top].end()) {
        visited[seq[idx]] = true;
        q.push(seq[idx]);
        idx++;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}