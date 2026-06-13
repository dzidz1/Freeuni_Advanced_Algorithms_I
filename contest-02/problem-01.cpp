#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    int ai, bi;
    pair<int, int> curr;
    cin >> ai >> bi;
    curr.first = ai;
    curr.second = bi;
    vec.push_back(curr);
  }
  sort(vec.begin(), vec.end());
  int best = -1;
  for (int i = 0; i < n; i++) {
    if (best <= vec[i].second) {
      best = vec[i].second;
    } else {
      best = vec[i].first;
    }
  }
  cout << best << endl;

  return 0;
}