#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> w;
  w.push_back(INT_MIN);
  for (int i = 0; i < n; i++) {
    int new_w;
    cin >> new_w;
    if (w.back() != new_w)
      w.push_back(new_w);
  }
  w.push_back(INT_MIN);
  int res = 0;
  for (int i = 1; i < w.size() - 1; i++) {
    if (w[i] > w[i - 1] && w[i] > w[i + 1])
      res++;
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}