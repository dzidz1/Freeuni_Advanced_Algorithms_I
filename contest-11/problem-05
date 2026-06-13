#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int get_g(int mask) {
  if (mask == 0)
    return 0;
  if (memo.count(mask))
    return memo[mask];

  int max_b = 31 - __builtin_clz(mask);
  set<int> s;

  for (int k = 1; k <= max_b + 1; k++) {
    int nxt = (mask >> k) | (mask & ((1 << (k - 1)) - 1));
    s.insert(get_g(nxt));
  }

  int mex = 0;
  while (s.count(mex))
    mex++;

  return memo[mask] = mex;
}

int main() {
  int n;
  cin >> n;

  map<int, int> masks;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int d = 2; d * d <= x; d++) {
      if (x % d == 0) {
        int c = 0;
        while (x % d == 0) {
          c++;
          x /= d;
        }
        masks[d] |= (1 << (c - 1));
      }
    }
    if (x > 1) {
      masks[x] |= (1 << 0);
    }
  }

  int xr = 0;
  for (auto const &[p, msk] : masks) {
    xr ^= get_g(msk);
  }

  if (xr > 0)
    cout << "Mojtaba\n";
  else
    cout << "Arpa\n";

  return 0;
}