#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string recipe;
  ll nb, ns, nc;
  ll pb, ps, pc;
  ll rub;
  cin >> recipe;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> rub;

  ll b_rec = 0, s_rec = 0, c_rec = 0;
  for (int i = 0; i < recipe.size(); i++) {
    if (recipe[i] == 'B')
      b_rec++;
    if (recipe[i] == 'S')
      s_rec++;
    if (recipe[i] == 'C')
      c_rec++;
  }

  ll total = 0;

  while ((nb > 0 && b_rec > 0) || (ns > 0 && s_rec > 0) ||
         (nc > 0 && c_rec > 0)) {
    ll need_b = max(0LL, b_rec - nb);
    ll need_s = max(0LL, s_rec - ns);
    ll need_c = max(0LL, c_rec - nc);
    ll cost = need_b * pb + need_s * ps + need_c * pc;

    if (rub >= cost) {
      rub -= cost;
      total++;
      nb = max(0LL, nb - b_rec);
      ns = max(0LL, ns - s_rec);
      nc = max(0LL, nc - c_rec);
    } else {
      cout << total << endl;
      return 0;
    }
  }

  ll cost_bur = b_rec * pb + s_rec * ps + c_rec * pc;
  if (cost_bur > 0)
    total += (rub / cost_bur);

  cout << total << endl;

  return 0;
}