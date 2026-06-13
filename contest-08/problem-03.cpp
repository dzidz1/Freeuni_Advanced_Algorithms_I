#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      if ((i + j) % 2 == 0) {
        if (num % 2 == 0)
          num++;
      } else {
        if (num % 2 == 1)
          num++;
      }
      cout << num << " ";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}