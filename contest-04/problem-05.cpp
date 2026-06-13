#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_VAL = 1000005;
int cnt[MAX_VAL];
ll current_power = 0;

struct Query {
  int l, r, id, block;

  bool operator<(const Query &other) const {
    if (block != other.block)
      return block < other.block;
    return (block % 2 == 0) ? (r < other.r) : (r > other.r);
  }
};

void add(int s) {
  current_power += (2LL * cnt[s] + 1) * s;
  cnt[s]++;
}

void remove(int s) {
  current_power -= (2LL * cnt[s] - 1) * s;
  cnt[s]--;
}

int main() {
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int block_size = max(1, (int)(n / sqrt(t)));
  vector<Query> queries(t);
  for (int i = 0; i < t; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].l--;
    queries[i].r--;
    queries[i].id = i;
    queries[i].block = queries[i].l / block_size;
  }

  sort(queries.begin(), queries.end());

  vector<ll> answers(t);
  int curL = 0, curR = -1;

  for (const auto &q : queries) {
    while (curR < q.r)
      add(a[++curR]);
    while (curL > q.l)
      add(a[--curL]);
    while (curR > q.r)
      remove(a[curR--]);
    while (curL < q.l)
      remove(a[curL++]);

    answers[q.id] = current_power;
  }

  for (int i = 0; i < t; i++) {
    cout << answers[i] << "\n";
  }

  return 0;
}