#include <bits/stdc++.h>
using namespace std;

vector<set<int>> owes;

int main() {
  int n, m;
  cin >> n >> m;

  owes.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    owes[u].insert(v);
  }

  vector<int> res;
  for (int i = 1; i <= n; i++) {
    res.push_back(i);
    int curr_idx = res.size() - 1;

    while (curr_idx > 0) {
      int left_person = res[curr_idx - 1];
      int me = res[curr_idx];

      if (owes[left_person].count(me)) {
        swap(res[curr_idx], res[curr_idx - 1]);
        curr_idx--;
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << (i == n - 1 ? "" : " ");
  }

  cout << endl;

  return 0;
}