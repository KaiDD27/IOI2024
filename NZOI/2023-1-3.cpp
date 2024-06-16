#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
vector<pair<ll, ll>> kp;
vector<vector<ll>> pRemainderPerSum;
ll n, d;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> d;
  kp.resize(d);
  // pi 1-50，余数 0-49
  pRemainderPerSum.resize(
      51,
      vector<ll>(50)); // Fix: Provide template arguments for vector constructor
  for (auto &[ki, pi] : kp) {
    cin >> ki >> pi;
  }
  sort(kp.begin(), kp.end());
  for (int ki = 1, kpi = 0; ki <= n; ki++) {
    ll togglesCnt = 0;
    while (kpi != d && kp[kpi].first == ki) {
      auto [ki, pi] = kp[kpi];
      ll remain = ki % pi;
      pRemainderPerSum[pi][remain]++;
      kpi++;
    }
    for (int pi = 1; pi <= 50; pi++) {
      ll remain = ki % pi;
      togglesCnt += pRemainderPerSum[pi][remain];
    }
    cout << ((togglesCnt % 2 == 0) ? "OFF" : "ON") << endl;
  }
  return 0;
}