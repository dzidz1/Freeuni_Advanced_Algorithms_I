#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nax = 2e5 + 5;

int n;
ll ans, t[nax];

struct Line {
  ll m, c;
  ll eval(ll x) { return m * x + c; }
};

bool is_bad(Line l1, Line l2, Line l3) {
  return (double)(l3.c - l1.c) / (l1.m - l3.m) <=
         (double)(l2.c - l1.c) / (l1.m - l2.m);
}

void rec(int l, int r) {
  if (l == r) {
    ans = max(ans, t[l]);
    return;
  }
  int mid = (l + r) / 2;

  rec(l, mid);
  rec(mid + 1, r);

  vector<Line> hull;
  ll s = 0, cur = 0;
  for (int i = mid; i >= l; --i) {
    s += t[i];
    cur += s;
    Line new_line = {mid - i + 1, cur};
    while (hull.size() >= 2 &&
           is_bad(hull[hull.size() - 2], hull.back(), new_line)) {
      hull.pop_back();
    }
    hull.push_back(new_line);
  }

  int ptr = 0;
  s = 0;
  cur = 0;
  for (int i = mid + 1; i <= r; ++i) {
    s += t[i];
    cur += t[i] * (i - mid);

    while (ptr + 1 < hull.size() &&
           hull[ptr].eval(s) <= hull[ptr + 1].eval(s)) {
      ptr++;
    }
    ans = max(ans, cur + hull[ptr].eval(s));
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> t[i];

  ans = 0;
  rec(1, n);

  cout << ans << endl;
  return 0;
}