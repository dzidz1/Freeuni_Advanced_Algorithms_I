#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int freq[MAXN][26];

void init(int k) {
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 26; j++) {
      freq[i][j] = 0;
    }
  }
}

int diff(int u, int v) {
  int ret = 0, maxi = 0;
  for (int j = 0; j < 26; j++) {
    ret += freq[u][j] + freq[v][j];
    maxi = max(maxi, freq[u][j] + freq[v][j]);
  }
  return ret - maxi;
}

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  init(k);
  for (int i = 0; i < n; i++) {
    freq[i % k][s[i] - 'a']++;
  }
  int res = 0;
  for (int i = 0; i < k; i++) {
    res += diff(i, k - i - 1);
  }
  cout << res / 2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}