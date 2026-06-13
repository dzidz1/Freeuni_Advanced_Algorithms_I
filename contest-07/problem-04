#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_VAL = (1 << 20);
const int MAX_N = 100005;
const int BLOCK_SIZE = 320;

int a[MAX_N];
ll freq[MAX_VAL];
ll current_ans = 0;
int k;

struct Query {
  int l, r, id, block;
  Query() {}
  Query(int _l, int _r, int _id) {
    l = _l;
    r = _r;
    id = _id;
    block = l / BLOCK_SIZE;
  }

  bool operator<(const Query &other) const {
    if (block != other.block)
      return block < other.block;
    return (block & 1) ? (r < other.r) : (r > other.r);
  }
};

void add(int x) {
  current_ans += freq[a[x] ^ k];
  freq[a[x]]++;
}

void remove(int x) {
  freq[a[x]]--;
  current_ans -= freq[a[x] ^ k];
}

int main() {
  int n, m;
  cin >> n >> m >> k;

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    a[i] = a[i - 1] ^ val;
  }

  vector<Query> queries;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    queries.push_back(Query(l - 1, r, i));
  }

  sort(queries.begin(), queries.end());

  vector<ll> answers(m);
  int cur_l = 0, cur_r = -1;

  for (int i = 0; i < m; i++) {
    int L = queries[i].l;
    int R = queries[i].r;

    while (cur_r < R)
      add(++cur_r);
    while (cur_l > L)
      add(--cur_l);
    while (cur_r > R)
      remove(cur_r--);
    while (cur_l < L)
      remove(cur_l++);

    answers[queries[i].id] = current_ans;
  }

  for (int i = 0; i < m; i++) {
    cout << answers[i] << "\n";
  }

  return 0;
}