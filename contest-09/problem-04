#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int p[N], f[N], res_len[N];

int main() {
  string s;
  cin >> s;
  int n = s.length();

  s = " " + s;
  int j = 0;
  for (int i = 2; i <= n; i++) {
    while (j > 0 && s[i] != s[j + 1])
      j = p[j];
    if (s[i] == s[j + 1])
      j++;
    p[i] = j;
  }

  for (int i = n; i >= 1; i--) {
    f[i]++;
    if (p[i] > 0)
      f[p[i]] += f[i];
  }

  int cnt_matches = 0;
  for (int i = n; i > 0; i = p[i]) {
    res_len[++cnt_matches] = i;
  }

  cout << cnt_matches << endl;
  for (int i = cnt_matches; i >= 1; i--) {
    int len = res_len[i];
    cout << len << " " << f[len] << endl;
  }

  return 0;
}
