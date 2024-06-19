#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, m;
string strS;
vector<ll> a;
vector<ll> change;
multimap<ll, ll> mmapCowLoseMilk;
ll remain = 0;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> m;
  a.resize(n + 2);
  change.resize(n + 2, -1);
  cin >> strS;
  strS = *strS.rbegin() + strS + *strS.begin();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    remain += a[i];
  }
  a[0] = a[n];
  a[n + 1] = a[1];
  for (ll i = 1; i <= n; i++) {
    if (strS[i - 1] == 'R')
      change[i]++;
    if (strS[i + 1] == 'L')
      change[i]++;
    if (change[i] == -1)
      mmapCowLoseMilk.insert({a[i], i});
  }
  ll timing = 0;
  while (timing < m && !mmapCowLoseMilk.empty()) {
    ll cap = mmapCowLoseMilk.begin()->first;
    if (cap >= m) {
      remain -= ((m - timing) * mmapCowLoseMilk.size());
      break;
    }
    remain -= ((cap - timing) * mmapCowLoseMilk.size());
    timing = cap;
    for (auto it = mmapCowLoseMilk.begin(); it != mmapCowLoseMilk.end();) {
      if (it->first != cap)
        break;
      if (strS[it->second] == 'L') {
        ll left;
        if (it->second == 1)
          left = n;
        else
          left = it->second - 1;
        change[left]--;
        if (change[left] == -1) // 加上cap放入map，这样就可以再支撑a[left]分钟了
          mmapCowLoseMilk.insert({a[left] + cap, left});
      }
      if (strS[it->second] == 'R') {
        ll right;
        if (it->second == n)
          right = 1;
        else
          right = it->second + 1;
        change[right]--;
        if (change[right] == -1)
          mmapCowLoseMilk.insert({a[right] + cap, right});
      }
      auto delIt = it;
      it++;
      mmapCowLoseMilk.erase(delIt);
    }
  }
  cout << remain << endl;
  return 0;
}