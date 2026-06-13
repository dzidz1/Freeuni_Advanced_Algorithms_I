#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  double p;
  cin >> n >> p >> t;
  vector<vector<double>> dp(t + 1, vector<double>(n + 1, 0.0));
  dp[0][0] = 1.0;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] == 0.0)
        continue;

      if (j == n) {
        dp[i + 1][j] += dp[i][j];
      } else {
        dp[i + 1][j + 1] += dp[i][j] * p;
        dp[i + 1][j] += dp[i][j] * (1.0 - p);
      }
    }
  }

  double exp_val = 0.0;
  for (int j = 0; j <= n; j++) {
    exp_val += dp[t][j] * j;
  }

  cout << fixed << setprecision(10) << exp_val << endl;

  return 0;
}