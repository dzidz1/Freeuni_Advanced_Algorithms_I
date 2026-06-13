#include <bits/stdc++.h>
using namespace std;

int find_r(string &s, int p, int &n) {
  int r = p;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1])
      r = i;
  }
  return r;
}

int find_l(string &s, int p, int &n) {
  int l = p;
  for (int i = n / 2 - 1; i >= 0; i--) {
    if (s[i] != s[n - i - 1])
      l = i;
  }
  return l;
}

int main() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  p--;
  if (p >= n / 2) {
    reverse(s.begin(), s.end());
    p = n - p - 1;
  }
  int r = find_r(s, p, n);
  int l = find_l(s, p, n);
  int moves = 0;
  bool needs_change = false;

  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      int diff = abs(s[i] - s[n - i - 1]);
      moves += min(diff, 26 - diff);
      needs_change = true;
    }
  }

  if (!needs_change) {
    cout << 0 << endl;
    return 0;
  }

  moves += (r - l) + min(abs(p - l), abs(p - r));

  cout << moves << endl;
  return 0;
}