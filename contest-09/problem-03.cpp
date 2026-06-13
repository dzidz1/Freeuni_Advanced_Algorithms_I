#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isGood(char ch, string &w) { return w[ch - 'a'] == '1'; }

struct Node {
  Node *next[26];
};

int main() {
  Node *head = new Node();
  string s;
  cin >> s;
  string w;
  cin >> w;
  ll k;
  cin >> k;
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int cnt = 0;
    Node *p = head;
    for (int j = i; j < s.size(); j++) {
      if (!isGood(s[j], w))
        cnt++;
      if (cnt > k)
        break;
      int c = s[j] - 'a';
      if (p->next[c] == NULL) {
        p->next[c] = new Node();
        ans++;
      }
      p = p->next[c];
    }
  }
  cout << ans << endl;
  return 0;
}
