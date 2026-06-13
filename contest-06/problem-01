#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<char> pattern(k, '?');
  bool pos = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      int j = i % k;
      if (pattern[j] != '?' && pattern[j] != s[i]) {
        pos = false;
        break;
      }
      pattern[j] = s[i];
    }
  }

  if (!pos) {
    cout << "NO" << endl;
    return;
  }

  int z = 0, o = 0;
  for (int i = 0; i < k; i++) {
    if (pattern[i] == '0')
      z++;
    else if (pattern[i] == '1')
      o++;
  }
  if (z > k / 2 || o > k / 2)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}