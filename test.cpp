#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, res[200005];
struct soldier {
  int id, l, r;
} s[400005];
int cmp(soldier a, soldier b) { return a.l < b.l; }

int go[400005][20];

void pre() {
  for (int i = 1, p = i; i <= 2 * n; i++) {
    while (p <= 2 * n && s[p].l <= s[i].r)
      p++;
    int pos = p - 1;
    go[i][0] = pos;
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      go[j][i] = go[go[j][i - 1]][i - 1];
    }
  }
}
void search(int k) {
  int lmt = s[k].l + m, ans = 1, p = k;
  for (int i = 19; i >= 0; i--) {
    if (go[k][i] != 0 && s[go[k][i]].r < lmt) {
      ans += (1 << i);
      k = go[k][i];
    }
  }
  res[s[p].id] = ans + 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].l >> s[i].r;
    if (s[i].r < s[i].l)
      s[i].r += m;
    s[i].id = i;
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    s[i + n] = s[i];
    s[i + n].l = s[i].l + m;
    s[i + n].r = s[i].r + m;
  }
  pre();
  for (int i = 1; i <= n; i++)
    search(i);
  for (int i = 1; i <= n; i++)
    cout << res[i] << " ";
  return 0;
}
