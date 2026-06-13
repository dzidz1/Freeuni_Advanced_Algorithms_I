#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> dp(n, 0);
  map<ll, ll> value;
  ll res = 0;

  for (ll i = 0; i < n; i++) {
    if (i > 0)
      dp[i] = dp[i - 1];

    if (value.count(a[i]))
      dp[i] += value[a[i]];

    value[a[i]] += (i + 1);
    res += dp[i];
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