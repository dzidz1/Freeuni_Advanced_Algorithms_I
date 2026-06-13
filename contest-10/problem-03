#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n, l, r;
  cin >> n >> l >> r;
  ll curr_pos = 1;
  bool found = 0;

  for (int i = 1; i < n; i++) {
    ll block_elems = 2LL * (n - i);

    if (curr_pos + block_elems > l) {
      for (int j = i + 1; j <= n; j++) {
        if (curr_pos >= l && curr_pos <= r) {
          cout << i << " ";
        }
        curr_pos++;

        if (curr_pos >= l && curr_pos <= r) {
          cout << j << " ";
        }
        curr_pos++;

        if (curr_pos > r) {
          found = true;
          break;
        }
      }
    } else {
      curr_pos += block_elems;
    }
    if (found)
      break;
  }

  if (curr_pos == l || (l <= n * (n - 1) + 1 && r >= n * (n - 1) + 1)) {
    if (curr_pos <= r) {
      cout << 1 << " ";
    }
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}