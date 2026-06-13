#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count_mins(int n, vector<int> &a) {
  vector<int> left(n), right(n);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.top()] >= a[i])
      s.pop();
    left[i] = s.empty() ? -1 : s.top();
    s.push(i);
  }
  while (!s.empty())
    s.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && a[s.top()] > a[i])
      s.pop();
    right[i] = s.empty() ? n : s.top();
    s.push(i);
  }

  ll sum_mins = 0;
  for (int i = 0; i < n; i++) {
    sum_mins += (ll)a[i] * (i - left[i]) * (right[i] - i);
  }

  return sum_mins;
}

ll count_maxs(int n, vector<int> &a) {
  vector<int> left(n), right(n);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.top()] <= a[i])
      s.pop();
    left[i] = s.empty() ? -1 : s.top();
    s.push(i);
  }
  while (!s.empty())
    s.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && a[s.top()] < a[i])
      s.pop();
    right[i] = s.empty() ? n : s.top();
    s.push(i);
  }

  ll sum_maxs = 0;
  for (int i = 0; i < n; i++) {
    sum_maxs += (ll)a[i] * (i - left[i]) * (right[i] - i);
  }

  return sum_maxs;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll res = count_maxs(n, a) - count_mins(n, a);
  cout << res << endl;

  return 0;
}
