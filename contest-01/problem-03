#include <bits/stdc++.h>
using namespace std;

int a[500010];
long long cnt[500010];

int main() {
  int n;
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }

  if (s % 3 != 0) {
    cout << "0" << endl;
    return 0;
  }

  s /= 3;
  long long curr_s = 0;
  for (int i = n - 1; i >= 0; i--) {
    curr_s += a[i];
    if (curr_s == s)
      cnt[i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  long long ans = 0;
  curr_s = 0;
  for (int i = 0; i + 2 < n; i++) {
    curr_s += a[i];
    if (curr_s == s)
      ans += cnt[i + 2];
  }
  cout << ans << endl;

  return 0;
}