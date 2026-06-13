#include <bits/stdc++.h>
using namespace std;

double a[20][20];
double dp[1 << 18];

int cnt_alive(int mask) {
  int cnt = 0;
  while (mask > 0) {
    if (mask & 1)
      cnt++;
    mask >>= 1;
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  dp[(1 << n) - 1] = 1.0;
  for (int mask = (1 << n) - 1; mask > 0; mask--) {
    int k = cnt_alive(mask);
    if (k <= 1)
      continue;

    double pairs = (double)(k * (k - 1)) / 2.0;

    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i)))
        continue;
      for (int j = 0; j < n; j++) {
        if (i == j || !(mask & (1 << j)))
          continue;
        int next_mask = mask ^ (1 << j);
        dp[next_mask] += dp[mask] * (a[i][j] / pairs);
      }
    }
  }

  cout << fixed << setprecision(6);
  for (int i = 0; i < n; i++)
    cout << dp[1 << i] << (i == n - 1 ? "" : " ");

  cout << endl;

  return 0;
}
