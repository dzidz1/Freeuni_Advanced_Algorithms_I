#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 200007;
ld t[MAXN], sum[MAXN], inv_sum[MAXN], pre[MAXN];
ld dp_old[MAXN], dp_new[MAXN];
ld x_val[MAXN], y_val[MAXN];
int deque_idx[MAXN];

inline ld cross_prod(int a, int b, int c) {
  return (x_val[b] - x_val[a]) * (y_val[c] - y_val[a]) -
         (x_val[c] - x_val[a]) * (y_val[b] - y_val[a]);
}

inline ld eval(int idx, ld slope) { return x_val[idx] - slope * y_val[idx]; }

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    sum[i] = sum[i - 1] + t[i];
    inv_sum[i] = inv_sum[i - 1] + (1.0 / t[i]);
    pre[i] = pre[i - 1] + (sum[i] / t[i]);
  }

  for (int i = 1; i <= n; i++) {
    dp_new[i] = pre[i];
  }

  for (int h = 2; h <= k; h++) {
    for (int i = 0; i <= n; i++) {
      dp_old[i] = dp_new[i];
      x_val[i] = dp_old[i] - pre[i] + sum[i] * inv_sum[i];
      y_val[i] = sum[i];
    }

    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++) {
      int curr_pt = i - 1;
      while (tail - head >= 2 &&
             cross_prod(deque_idx[tail - 2], deque_idx[tail - 1], curr_pt) >=
                 0) {
        tail--;
      }
      deque_idx[tail++] = curr_pt;

      ld curr_slope = inv_sum[i];
      while (tail - head >= 2 && eval(deque_idx[head + 1], curr_slope) <=
                                     eval(deque_idx[head], curr_slope)) {
        head++;
      }

      int best_j = deque_idx[head];
      dp_new[i] = pre[i] + eval(best_j, curr_slope);
    }
  }

  cout << fixed << setprecision(10) << dp_new[n] << endl;

  return 0;
}