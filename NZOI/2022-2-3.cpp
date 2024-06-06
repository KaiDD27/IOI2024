#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n;
set<ll> stSum;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n;
  ll sumV = 0;
  stSum.insert(0);
  for (int i = 0; i < n; i++) {
    ll vi;
    cin >> vi;
    sumV += vi;
    set<ll> stTmp = stSum;
    for (auto si : stTmp) {
      if (si + vi > 200)
        break;
      stSum.insert(si + vi);
    }
  }
  ll ans = 0;
  for (auto si : stSum) {
    ans = max(ans, min(si, 100ll) * (sumV - si));
    if (si >= 100)
      break;
  }
  cout << ans << endl;
  return 0;
}