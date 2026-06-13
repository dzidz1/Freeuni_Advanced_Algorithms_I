#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string ab = "AB";
  string ba = "BA";

  auto ab_idx = s.find(ab);
  auto ba_idx = s.find(ba);

  if (ab_idx != string::npos && s.find(ba, ab_idx + 2) != string::npos) {
    cout << "YES" << endl;
  } else if (ba_idx != string::npos && s.find(ab, ba_idx + 2) != string::npos) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}