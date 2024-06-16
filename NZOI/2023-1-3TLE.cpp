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
vector<vector<map<ll, ll>>> pRemainderMpIToPerSum;
ll n, d;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> d;
  kp.resize(d);
  // pi 1-50，余数 0-49
  pRemainderMpIToPerSum.resize(
      51, vector<map<ll, ll>>(
              50)); // Fix: Provide template arguments for vector constructor
  for (auto &[ki, pi] : kp) {
    cin >> ki >> pi;
  }
  sort(kp.begin(), kp.end());
  for (auto [ki, pi] : kp) {
    ll remain = ki % pi;
    auto &mpPK = pRemainderMpIToPerSum[pi][remain];
    if (mpPK.empty())
      mpPK[ki] = 1;
    else
      mpPK[ki] = mpPK.rbegin()->second + 1;
  }
  for (int ki = 1; ki <= n; ki++) {
    ll togglesCnt = 0;
    for (int pi = 1; pi <= 50; pi++) {
      ll remain = ki % pi;
      auto mpPK = pRemainderMpIToPerSum[pi][remain];
      if (!mpPK.empty()) {
        auto it = mpPK.upper_bound(ki);
        if (it != mpPK.begin()) {
          it--;
          togglesCnt += it->second;
        }
      }
    }
    cout << ((togglesCnt % 2 == 0) ? "OFF" : "ON") << endl;
  }
  return 0;
}