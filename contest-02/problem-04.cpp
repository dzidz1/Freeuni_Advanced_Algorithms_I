#include <bits/stdc++.h>
using namespace std;

int calc_min(vector<int> &heights, int left, int right, int curr_lvl) {
  if (left > right)
    return 0;

  int min_idx = left;
  for (int i = left + 1; i <= right; i++) {
    if (heights[i] < heights[min_idx]) {
      min_idx = i;
    }
  }

  int min_height = heights[min_idx];

  int vert_strokes = right - left + 1;
  int hor_strokes = min_height - curr_lvl;

  int total_hor = hor_strokes +
                  calc_min(heights, left, min_idx - 1, min_height) +
                  calc_min(heights, min_idx + 1, right, min_height);

  return min(vert_strokes, total_hor);
}

int main() {
  int n;
  cin >> n;
  vector<int> heights(n);

  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  cout << calc_min(heights, 0, n - 1, 0) << endl;

  return 0;
}
