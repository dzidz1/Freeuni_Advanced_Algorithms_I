#include <bits/stdc++.h>
using namespace std;

double get_max_subarray_sum(int n, const vector<double> &b) {
  double max_so_far = 0, current_max = 0;

  for (int i = 0; i < n; i++) {
    current_max += b[i];
    if (current_max > max_so_far)
      max_so_far = current_max;
    if (current_max < 0)
      current_max = 0;
  }

  return max_so_far;
}

double calculate_poorness(double x, int n, const vector<int> &a) {
  vector<double> modified_a(n);
  vector<double> negative_modified_a(n);

  for (int i = 0; i < n; i++) {
    modified_a[i] = a[i] - x;
    negative_modified_a[i] = -(a[i] - x);
  }

  double max_sum = get_max_subarray_sum(n, modified_a);
  double min_sum_abs = get_max_subarray_sum(n, negative_modified_a);

  return max(max_sum, min_sum_abs);
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  double low = -20000.0;
  double high = 20000.0;

  for (int i = 0; i < 100; i++) {
    double mid = (low + high) / 2.0;

    vector<double> b(n);
    for (int j = 0; j < n; j++)
      b[j] = a[j] - mid;
    double vp = get_max_subarray_sum(n, b);

    for (int j = 0; j < n; j++)
      b[j] = -b[j];
    double vn = get_max_subarray_sum(n, b);

    if (vp > vn)
      low = mid;
    else
      high = mid;
  }

  double final_x = (low + high) / 2.0;
  cout << fixed << setprecision(12) << calculate_poorness(final_x, n, a)
       << endl;

  return 0;
}