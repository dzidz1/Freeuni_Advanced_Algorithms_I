#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 1005;

int n, m;
string s;
int l_occ[M], r_occ[M];

void find_occ(const string &t, int *occ) {
  int m_len = t.length();
  vector<int> p(m_len + 1, 0);
  for (int i = 1, j = 0; i < m_len; i++) {
    while (j > 0 && t[i] != t[j])
      j = p[j];
    if (t[i] == t[j])
      j++;
    p[i + 1] = j;
  }

  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (cur > 0 && s[i] != t[cur])
      cur = p[cur];
    if (s[i] == t[cur])
      cur++;
    occ[cur] = min(occ[cur], i);
    if (cur == m_len)
      cur = p[cur];
  }
}

int main() {
  cin >> s >> m;
  n = s.length();

  int ans = 0;
  while (m--) {
    string p;
    cin >> p;
    int len = p.length();
    if (len < 2)
      continue;

    for (int i = 0; i <= len; i++) {
      l_occ[i] = n;
      r_occ[i] = n;
    }

    find_occ(p, l_occ);

    string rs = s, rp = p;
    reverse(rs.begin(), rs.end());
    reverse(rp.begin(), rp.end());

    string temp_s = s;
    s = rs;
    find_occ(rp, r_occ);
    s = temp_s;

    bool possible = false;
    for (int i = 1; i < len; i++) {
      int left_end = l_occ[i];
      int right_start = n - 1 - r_occ[len - i];
      if (left_end < right_start) {
        possible = true;
        break;
      }
    }
    if (possible)
      ans++;
  }

  cout << ans << endl;

  return 0;
}