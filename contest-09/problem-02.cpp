#include <bits/stdc++.h>
using namespace std;

vector<int> validate(int n, vector<int> a, int x) {
  multiset<int> s;
  for (auto elem : a)
    s.insert(elem);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    auto max_it = s.end();
    max_it--;
    int sec = x - *max_it;
    s.erase(max_it);
    auto sec_it = s.find(sec);
    if (sec_it == s.end())
      return {};
    res.push_back(x - sec);
    res.push_back(sec);
    x = max(x - sec, sec);
    s.erase(sec_it);
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n, 0);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < 2 * n - 1; i++) {
    int x = a[i] + a[2 * n - 1];
    vector<int> res = validate(n, a, x);
    if (res.size() > 0) {
      cout << "YES" << endl;
      cout << x << endl;
      for (int j = 0; j < n; j++) {
        cout << res[2 * j] << " " << res[2 * j + 1] << endl;
      }
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
