#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, q;
vector<ll> c, t;
map<ll, ll> mpGap;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> q;
  c.resize(n);
  t.resize(n);
  for (auto &ci : c)
    cin >> ci;
  for (auto &ti : t)
    cin >> ti;
  for (int i = 0; i < n; i++) {
    mpGap[c[i] - t[i]]++;
  }
  ll sumCnt = 0;
  for (auto it = mpGap.rbegin(); it != mpGap.rend(); it++) {
    if (it->first > 0) {
      it->second += sumCnt;
      sumCnt = it->second;
    }
  }
  // 加个墙确保不会越界
  mpGap[1e6 + 10] = 0;
  for (int i = 0; i < q; i++) {
    ll vi, si;
    cin >> vi >> si;
    if (mpGap.upper_bound(si)->second >= vi)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}