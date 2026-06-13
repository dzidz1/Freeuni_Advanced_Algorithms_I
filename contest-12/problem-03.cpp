#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
};

double dist(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
  Point adil, bera, bin;
  cin >> adil.x >> adil.y >> bera.x >> bera.y >> bin.x >> bin.y;
  int n;
  cin >> n;

  vector<Point> bottles(n);
  double base_dist = 0;
  vector<pair<double, int>> adil_savings;
  vector<pair<double, int>> bera_savings;

  for (int i = 0; i < n; i++) {
    cin >> bottles[i].x >> bottles[i].y;

    double d_bin = dist(bin, bottles[i]);
    double d_adil = dist(adil, bottles[i]);
    double d_bera = dist(bera, bottles[i]);

    base_dist += 2 * d_bin;
    adil_savings.push_back({d_adil - d_bin, i});
    bera_savings.push_back({d_bera - d_bin, i});
  }

  sort(adil_savings.begin(), adil_savings.end());
  sort(bera_savings.begin(), bera_savings.end());

  double min_total = base_dist + adil_savings[0].first;
  min_total = min(min_total, base_dist + bera_savings[0].first);

  int limit_a = min(2, n);
  int limit_b = min(2, n);

  for (int i = 0; i < limit_a; ++i) {
    for (int j = 0; j < limit_b; ++j) {
      if (adil_savings[i].second != bera_savings[j].second) {
        double current_combination =
            base_dist + adil_savings[i].first + bera_savings[j].first;
        min_total = min(min_total, current_combination);
      }
    }
  }

  cout << fixed << setprecision(12) << min_total << endl;
  return 0;
}