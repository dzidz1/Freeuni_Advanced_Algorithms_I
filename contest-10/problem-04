#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500050;
const int K = 750;

int a[N];
int sum[K][K];

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i < K; i++) {
        sum[i][x % i] += y;
      }
    } else {
      if (x >= K) {
        int res = 0;
        for (int i = y; i <= N - 50; i += x) {
          res += a[i];
        }
        cout << res << endl;
      } else {
        cout << sum[x][y] << endl;
      }
    }
  }
  return 0;
}