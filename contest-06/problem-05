#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

ll power(ll b, ll e) {
  ll r = 1;
  b %= MOD;
  while (e > 0) {
    if (e % 2 == 1)
      r = (r * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return r;
}

ll inv(ll n) { return power(n, MOD - 2); }

int main() {
  int n;
  cin >> n;

  ll inv100 = inv(100);
  ll a = 1, b = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ll p = (x * inv100) % MOD;
    ll ip = inv(p);

    ll na = (a - (1 - p + MOD) % MOD + MOD) % MOD;
    a = (na * ip) % MOD;

    ll nb = (b - 1 + MOD) % MOD;
    b = (nb * ip) % MOD;
  }

  ll res = (MOD - b) % MOD;
  res = (res * inv(a)) % MOD;

  cout << res << "\n";
  return 0;
}