#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll l, r;
  cin >> l >> r;
  if (l == r) {
    cout << 0 << endl;
    return 0;
  }
  ll diff = l ^ r;
  ll max_xor = 0;
  int msb = 0;
  for (int i = 62; i >= 0; i--) {
    if ((diff >> i) & 1) {
      msb = i;
      break;
    }
  }
  cout << (1LL << (msb + 1)) - 1 << endl;
  return 0;
}