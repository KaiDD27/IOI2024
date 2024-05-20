#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
#define endl "\n"
const ll MOD = 10000;
const int U = 0, V = 1;
ll a, b, c, d, n;
map<array<ll, 2>, ll> mpUZtoN;
map<ll, array<ll, 2>> mpNtoUZ;
vector<array<ll, 2>> dp(2);
int main() {
  ios::sync_with_stdio(false); // Fast I/O
  cin.tie(nullptr); // Not safe to use cin/cout & scanf/printf together
  cin >> a >> b >> c >> d >> n;
  int now = 0, old = 1;
  dp[now] = {1, 1};
  mpUZtoN[{1, 1}] = 0;
  mpNtoUZ[0] = {1, 1};
  ll cycleStart = -1;
  ll cycleLength = -1;
  for (ll i = 1; i <= n; i++) {
    swap(now, old);
    auto [u, v] = dp[old];
    dp[now][U] = (a * u + b * v) % MOD;
    dp[now][V] = (c * u + d * v) % MOD;

    if (mpUZtoN.count({dp[now][U], dp[now][V]})) {
      cycleStart = mpUZtoN[{dp[now][U], dp[now][V]}];
      cycleLength = i - cycleStart;
      break;
    }
    mpUZtoN[{dp[now][U], dp[now][V]}] = i;
    mpNtoUZ[i] = {{dp[now][U], dp[now][V]}};
  }
  if (cycleStart == -1) {
    cout << dp[now][U] << " " << dp[now][V] << endl;
    return 0;
  }
  ll idx = (n - cycleStart) % cycleLength + cycleStart;
  cout << mpNtoUZ[idx][U] << " " << mpNtoUZ[idx][V] << endl;

  return 0;
}