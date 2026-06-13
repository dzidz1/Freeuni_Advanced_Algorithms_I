#include <bits/stdc++.h>
using namespace std;

int a[300005];

int isHV(int i, int n) {
  if (i <= 0 || i >= n - 1)
    return 0;
  if (a[i] > a[i - 1] && a[i] > a[i + 1])
    return 1;
  if (a[i] < a[i - 1] && a[i] < a[i + 1])
    return 1;
  return 0;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n < 3) {
    cout << 0 << "\n";
    return;
  }

  int hv_cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    hv_cnt += isHV(i, n);
  }

  int max_diff = 0;
  for (int i = 0; i < n; i++) {
    int init = a[i];

    int before = isHV(i - 1, n) + isHV(i, n) + isHV(i + 1, n);

    if (i > 0) {
      a[i] = a[i - 1];
      max_diff = max(max_diff,
                     before - (isHV(i - 1, n) + isHV(i, n) + isHV(i + 1, n)));
    }

    if (i < n - 1) {
      a[i] = a[i + 1];
      max_diff = max(max_diff,
                     before - (isHV(i - 1, n) + isHV(i, n) + isHV(i + 1, n)));
    }

    a[i] = init;
  }

  cout << hv_cnt - max_diff << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}