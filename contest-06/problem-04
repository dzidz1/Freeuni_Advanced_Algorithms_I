#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int res = 0;
  for (int mx = 1; mx <= 30; mx++) {
    int curr_sum = 0;
    int best_sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > mx) {
        curr_sum = 0;
      } else {
        curr_sum += a[i];
        if (curr_sum < 0)
          curr_sum = 0;
      }
      best_sum = max(best_sum, curr_sum);
    }
    res = max(res, best_sum - mx);
  }
  cout << res << endl;
  return 0;
}