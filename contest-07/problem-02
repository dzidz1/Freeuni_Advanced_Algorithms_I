#include <bits/stdc++.h>
using namespace std;

void sol() {
  int n;
  cin >> n;
  vector<int> a(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }

  bool yes = !a[n];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j < n; j++) {
      yes |= (a[i] == (a[j] ^ a[i]) && a[i] == (a[n] ^ a[j]));
    }
  }

  if (yes)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}