#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
ll n, k;
map<ll, ll> mpPtoI;
set<ll> stI;
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    ll pi;
    cin >> pi;
    mpPtoI[pi] = i;
  }
  for (int ki = 1; ki <= k; ki++) {
    stI.insert(mpPtoI[ki]);
  }
  ll ans = LLONG_MAX;
  ans = *stI.rbegin() - *stI.begin();
  for (int ki = k + 1; ki <= n; ki++) {
    stI.erase(mpPtoI[ki - k]);
    stI.insert(mpPtoI[ki]);
    ans = min(ans, *stI.rbegin() - *stI.begin());
  }
  cout << ans << endl;

  return 0;
}