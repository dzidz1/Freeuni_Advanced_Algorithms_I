#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  bool poss = 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] % a[i] != 0) {
      poss = 0;
      break;
    }
  }
  if (!poss) {
    cout << 0 << endl;
    return;
  }

  vector<int> primes;
  int temp = a[0];
  for (int d = 2; d * d <= temp; d++) {
    if (temp % d == 0) {
      primes.push_back(d);
      while (temp % d == 0)
        temp /= d;
    }
  }
  if (temp > 1)
    primes.push_back(temp);

  ll total = 1;
  for (int i = 1; i < n; i++) {
    int target = a[i - 1] / a[i];
    int k_max = m / a[i];

    vector<int> active_primes;
    for (int p : primes) {
      if (target % p == 0)
        active_primes.push_back(p);
    }

    int num_primes = active_primes.size();
    int valid_k_cnt = 0;

    for (int mask = 0; mask < (1 << num_primes); mask++) {
      int prime_prod = 1;
      int set_bits = 0;

      for (int j = 0; j < num_primes; j++) {
        if ((mask >> j) & 1) {
          prime_prod *= active_primes[j];
          set_bits++;
        }
      }

      if (set_bits % 2 == 1) {
        valid_k_cnt -= (k_max / prime_prod);
      } else {
        valid_k_cnt += (k_max / prime_prod);
      }
    }
    total = (total * (valid_k_cnt % MOD)) % MOD;
  }

  cout << (total + MOD) % MOD << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}