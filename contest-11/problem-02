#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll powr(ll base, ll exp) {
  ll res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

ll modInv(ll n) { return powr(n, mod - 2); }

ll c(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  vector<ll> fact(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  ll num = fact[n];
  ll den = (fact[k] * fact[n - k]) % mod;

  return (num * modInv(den)) % mod;
}

int main() {
  int n, m;
  cin >> n >> m;
  ll res = c(n + 2 * m - 1, 2 * m) % mod;
  cout << res << endl;
  return 0;
}