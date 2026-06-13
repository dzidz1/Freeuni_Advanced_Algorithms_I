#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
      if (a[i].empty())
        continue;
      a[i].push_back(n);
    }

    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (a[i].empty()) {
        res[i] = n + 1;
        continue;
      }
      res[i] = a[i][0] + 1;
      for (int j = 0; j < a[i].size() - 1; j++) {
        res[i] = max(res[i], a[i][j + 1] - a[i][j]);
      }
    }

    vector<set<int>> rev(n + 1);
    for (int i = 1; i <= n; i++) {
      if (res[i] <= n) {
        rev[res[i]].insert(i);
      }
    }

    int last = n + 1;
    for (int i = 1; i <= n; i++) {
      if (rev[i].empty() && last == n + 1) {
        cout << -1 << " ";
      } else if (rev[i].empty() && last != n + 1) {
        cout << last << " ";
      } else {
        int curr = *(rev[i].begin());
        cout << min(curr, last) << " ";
        last = min(curr, last);
      }
    }
    cout << endl;
  }

  return 0;
}