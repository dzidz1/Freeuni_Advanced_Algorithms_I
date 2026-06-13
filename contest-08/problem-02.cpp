#include <bits/stdc++.h>
using namespace std;

vector<int> make_zero(int n, string s) {
  vector<int> moves;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1])
      moves.push_back(i + 1);
  }

  if (s[n - 1] == '1')
    moves.push_back(n);
  return moves;
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  vector<int> moves_a = make_zero(n, a);
  vector<int> moves_b = make_zero(n, b);

  vector<int> moves = moves_a;
  for (int i = moves_b.size() - 1; i >= 0; i--) {
    moves.push_back(moves_b[i]);
  }

  cout << moves.size();
  for (int x : moves)
    cout << " " << x;
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}