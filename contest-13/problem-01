#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<ll> p(n + 1);
  vector<ll> psum(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    psum[i] = psum[i - 1] + p[i];
  }

  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i * m > j) {
        dp[i][j] = 0;
      } else {
        ll skip = dp[i][j - 1];

        ll curr_seg_sum = psum[j] - psum[j - m];
        ll include = dp[i - 1][j - m] + curr_seg_sum;

        dp[i][j] = max(skip, include);
      }
    }
  }

  cout << dp[k][n] << endl;

  return 0;
}