#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int BLOCK_SIZE = 320;

struct Query {
  int l, r, id;
};

bool compareQueries(const Query &a, const Query &b) {
  int blockA = a.l / BLOCK_SIZE;
  int blockB = b.l / BLOCK_SIZE;
  if (blockA != blockB)
    return blockA < blockB;
  return (blockA & 1) ? (a.r < b.r) : (a.r > b.r);
}

int n, m;
int a[MAX_N];
int freq[MAX_N];
int special_count = 0;
int answers[MAX_N];

void add(int val) {
  if (val >= MAX_N)
    return;
  if (freq[val] == val)
    special_count--;
  freq[val]++;
  if (freq[val] == val)
    special_count++;
}

void remove(int val) {
  if (val >= MAX_N)
    return;
  if (freq[val] == val)
    special_count--;
  freq[val]--;
  if (freq[val] == val)
    special_count++;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<Query> queries(m);
  for (int i = 0; i < m; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].l--;
    queries[i].r--;
    queries[i].id = i;
  }

  sort(queries.begin(), queries.end(), compareQueries);

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
    answers[q.id] = special_count;
  }

  for (int i = 0; i < m; i++) {
    cout << answers[i] << endl;
  }

  return 0;
}