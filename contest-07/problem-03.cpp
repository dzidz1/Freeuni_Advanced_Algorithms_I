#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int a[1005];
    int count[1005];
    int moves[5005];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < 1005) {
        count[a[i]]++;
      }
    }

    int step_count = 0;

    while (true) {
      int i;
      for (i = 1; i < n && a[i] >= a[i - 1]; i++)
        ;

      if (i >= n)
        break;

      int mex = 0;
      while (count[mex] > 0) {
        mex++;
      }

      int target_idx;
      if (mex < n) {
        target_idx = mex;
      } else {
        for (i = 0; i < n && a[i] == i; i++)
          ;
        target_idx = i;
      }

      moves[step_count++] = target_idx;
      count[a[target_idx]]--;
      a[target_idx] = mex;
      count[mex]++;
    }

    cout << step_count << endl;
    for (int i = 0; i < step_count; i++) {
      cout << moves[i] + 1 << (i == step_count - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}