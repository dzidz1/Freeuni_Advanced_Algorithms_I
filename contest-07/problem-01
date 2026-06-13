#include <bits/stdc++.h>
using namespace std;

void sol() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> freq(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }

  vector<bool> is_special(n + 1, false);
  for (int i = 0; i < n; i++) {
    for (int j = i + 2; j <= n; j++) {
      int curr_sum = pref[j] - pref[i];
      if (curr_sum <= n) {
        is_special[curr_sum] = true;
      } else {
        break;
      }
    }
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (is_special[i]) {
      count += freq[i];
    }
  }

  cout << count << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}