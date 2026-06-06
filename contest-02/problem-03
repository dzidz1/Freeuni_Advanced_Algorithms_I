#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000000;

int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;

  int dp[101][101][2] = {0};
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;

  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      for (int k = 1; k <= k1; k++) {
        if (i >= k)
          dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
      }

      for (int k = 1; k <= k2; k++) {
        if (j >= k)
          dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
      }
    }
  }

  int res = (dp[n1][n2][0] + dp[n1][n2][1]) % MOD;
  cout << res << endl;

  return 0;
}
