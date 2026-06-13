#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX = 4000005;

vector<ll> fact(MAX), invFact(MAX);

ll powr(ll base, ll exp) {
  ll res = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}

void precompute() {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  invFact[MAX - 1] = powr(fact[MAX - 1], MOD - 2);
  for (int i = MAX - 2; i >= 0; i--) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

ll c(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;
  return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

ll stars_and_bars(int bins, int objects) {
  if (objects == 0)
    return 1;
  if (bins == 0)
    return 0;
  return c(bins + objects - 1, objects);
}

void solve() {
  int n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;

  if (n1 + n2 == 0) {
    if (n3 == 0 || n4 == 0) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return;
  }

  if (abs(n1 - n2) > 1) {
    cout << 0 << endl;
    return;
  }

  ll total_ways = 0;

  if (n1 == n2) {
    ll ways1 = (stars_and_bars(n1 + 1, n3) * stars_and_bars(n2, n4)) % MOD;
    ll ways2 = (stars_and_bars(n1, n3) * stars_and_bars(n2 + 1, n4)) % MOD;
    total_ways = (ways1 + ways2) % MOD;
  } else if (n2 > n1) {
    total_ways = (stars_and_bars(n1 + 1, n3) * stars_and_bars(n2, n4)) % MOD;
  } else {
    total_ways = (stars_and_bars(n1, n3) * stars_and_bars(n2 + 1, n4)) % MOD;
  }

  cout << total_ways << endl;
}

int main() {
  precompute();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}