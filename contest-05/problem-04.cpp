#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

vector<vector<ll>> mat_mul(vector<vector<ll>> &A, vector<vector<ll>> &B,
                           int n) {
  vector<vector<ll>> C(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if (A[i][k] == 0)
        continue;
      for (int j = 0; j < n; j++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll k, int n) {
  vector<vector<ll>> res(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++)
    res[i][i] = 1;

  while (k > 0) {
    if (k % 2 == 1)
      res = mat_mul(res, A, n);
    A = mat_mul(A, A, n);
    k /= 2;
  }

  return res;
}

int main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;

  vector<vector<ll>> adj(n, vector<ll>(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1][v - 1] = 1;
  }

  vector<vector<ll>> res_mat = power(adj, k, n);
  ll total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      total = (total + res_mat[i][j]) % MOD;
    }
  }

  cout << total << endl;

  return 0;
}
