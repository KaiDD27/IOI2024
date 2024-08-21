#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
int n;
ll a;
map<ll, map<ll, ll>> rows;
int main() {
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    ll r, c;
    cin >> r >> c;
    for (ll ri = max(0LL, r - a); ri < r + a + 1; ri++) {
      rows[ri][max(0LL, c - a)] += 1;
      rows[ri][c + a + 1] -= 1;
    }
  }
  ll res = 0;
  for (auto &row : rows) {
    ll cnt = 0;
    ll prev = 0;
    for (auto &cur : row.second) {
      if (cnt > 0) {
        res += cur.first - prev;
      }
      cnt += cur.second;
      prev = cur.first;
    }
  }
  cout << res;
}