#include <bits/stdc++.h>
using namespace std;

bool can(int m, int s) { return s >= 0 && s <= 9 * m; }

int main() {
  int m, s, sum;
  string min_n = "", max_n = "";
  cin >> m >> s;

  if (s == 0) {
    if (m == 1)
      cout << "0 0" << endl;
    else
      cout << "-1 -1" << endl;
    return 0;
  }

  if (s > 9 * m) {
    cout << "-1 -1" << endl;
    return 0;
  }

  sum = s;
  for (int i = 0; i < m; i++) {
    for (int d = 0; d < 10; d++) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d)) {
        min_n += char('0' + d);
        sum -= d;
        break;
      }
    }
  }

  sum = s;
  for (int i = 0; i < m; i++) {
    for (int d = 9; d >= 0; d--) {
      if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d)) {
        max_n += char('0' + d);
        sum -= d;
        break;
      }
    }
  }

  cout << min_n << " " << max_n << endl;

  return 0;
}
